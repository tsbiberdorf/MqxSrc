'''
/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: ddcopy.py$
* $Version : 3.8.4.0$
* $Date    : Oct-3-2012$
*
*END************************************************************************/
'''


import sys, re, os, pprint, wmi
import ctypes
import binascii
import struct
import win32file
import win32con
import winioctlcon
import collections
import elftools.elf.elffile as elffile


class DeviceManager(object):
	''' singleton implementation, manage device resource '''
	class DeviceInfo(object):
		''' physical device object '''
		def __init__(self, params):
			for param in ['BlockSize', 'Filename', 'Size', 'Volumes']:
				if (param not in params): raise Exception("Missing param {PARAM}" . format(PARAM=param))
			self._blockSize = params['BlockSize']
			self._filename = params['Filename']
			self._size = params['Size']
			self._volumes = []
			if (params['Volumes']): self._volumes = params['Volumes']
		@property 
		def BlockSize(self): return self._blockSize
		@property
		def Filename(self): return self._filename
		@property 
		def Size(self): return self._size
		@property
		def Volumes(self): return iter(self._volumes)
		
	''' singleton object '''
	_instance = None
	def __new__(cls, *args, **kwargs):
		''' implementing singleton '''
		if (cls._instance is None):
			cls._instance = super(DeviceManager, cls).__new__(cls, *args, **kwargs)
		return cls._instance
	
	def __init__(self):
	# create tables
		self._tableDisc = {}
		self._tableVolume = {}
		self._indexPart2Disc = {}
		self._indexPart2Volumes = {}
		self._indexDisc2Volumes = {}
		self._indexVolume2Disc = {}
	# create disc indexes/table 
		for item in wmi.WMI().Win32_DiskDrive():
			discKey = str(item.DeviceID).upper()
		# check whether 'Capabilities' is iterable 
			if (not isinstance(item.Capabilities, collections.Iterable)): continue
		# do not use non-removable disc
			if (7 not in item.Capabilities): continue
			self._tableDisc[discKey] = item
	# create partition indexes/table  
		for item in wmi.WMI().Win32_DiskDriveToDiskPartition():
			partKey = str(item.Dependent.DeviceID).upper()
			discKey = str(item.Antecedent.DeviceID).upper()
		# skip partition if associated disc is not in table
			if (discKey not in self._tableDisc): continue
		# add records to tables
			self._indexPart2Disc[partKey] = item.Antecedent.DeviceID
	# create volume indexes/table
		for item in wmi.WMI().Win32_LogicalDiskToPartition():
			volumeKey = str(item.Dependent.DeviceID).upper()
			partKey = str(item.Antecedent.DeviceID).upper()
		# skip volume if associated partition is not in table
			if (partKey not in self._indexPart2Disc): continue
		# add records to tables
			discKey = str(self._indexPart2Disc[partKey]).upper()
			if (discKey not in self._indexDisc2Volumes): self._indexDisc2Volumes[discKey] = []
			self._indexDisc2Volumes[discKey].append(volumeKey)
			self._indexVolume2Disc[volumeKey] = discKey
			self._tableVolume[volumeKey] = item.Dependent
	
	def GetVolumeFilename(self, volume):
		volume = str(volume).upper()
		return "\\\\.\\{VOLUME}" . format(VOLUME=volume)
	
	def VolumeExists(self, volume):
		volume = str(volume).upper()
		return volume in self._tableVolume
	
	def GetVolumesName(self):
		return self._tableVolume.keys()
	
	def GetDeviceInfoByVolume(self, volume):
		volume = str(volume).upper()
		discKey = self._indexVolume2Disc[volume]
		disc = self._tableDisc[discKey]
		volumes = self._indexDisc2Volumes[discKey]
		result = DeviceManager.DeviceInfo({
			'BlockSize' : disc.BytesPerSector,
			'Filename'	: disc.DeviceID,
			'Size'		: disc.Size,
			'Volumes'	: volumes
		})
		return result


class CmdArguments(object):
	''' command line arguments to object, singleton '''
	_instance = None
	def __new__(cls, *args, **kwargs):
		if (cls._instance is None):
			cls._instance = super(CmdArguments, cls).__new__(cls, *args, **kwargs)
		return cls._instance
	
	def __init__(self):
		self._arguments = {}
		for arg in sys.argv:
			result = re.search("([^=]+)=(.*)", arg)
			if (result): self._arguments[result.group(1)] = result.group(2)
			else: self._arguments[arg] = arg
	
	def Get(self, key):
		''' get argument's value by argument's key '''
		if (key not in self._arguments): return None
		return self._arguments[key]
	
	def Exists(self, key):
		''' check whether argument's key exists '''
		return (key in self._arguments)


class ReadFile(object):
	def __init__(self, path):
		self._file = None
		self._path = path
		self._startFrom = 0
		self._blockSize = 0
		self._size = 0
		self._readed = 0
	
	def Open(self):
		self._file = open(self._path, "rb")
		self._file.seek(self._startFrom)
	
	def Close(self):
		self._file.close()
	
	@property
	def StartFrom(self): return self._startFrom
	
	@StartFrom.setter
	def StartFrom(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._startFrom = value
	
	@property
	def Size(self): return self._size
	@Size.setter
	def Size(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._size = value
	
	@property
	def BlockSize(self): return self._blockSize
	
	@BlockSize.setter
	def BlockSize(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._blockSize = value
	
	def _ReadAll(self):
		data = self._file.read()
		return data
	
	def _ReadSize(self):
		data = self._file.read(self._size)
		
		
		return data
	
	def _ReadSizeByBlock(self):
		remains = (self._size - self._readed)
		readSize = self._blockSize if (remains > self._blockSize) else remains
		data = self._file.read(readSize)
		self._readed += len(data)
		return data
	
	def _ReadByBlock(self):
		data = self._file.read(self._blockSize)
		return data
	
	def Read(self):
		data = None
		if (self._blockSize == 0 and self._size == 0):
			data = self._ReadAll()
		elif (self._blockSize == 0 and self._size > 0):
			data = self._ReadSize()
		elif (self._blockSize > 0 and self._size == 0):
			data = self._ReadByBlock()
		elif (self._blockSize > 0 and self._size > 0):
			data = self._ReadSizeByBlock()
		else:
			raise Exception("Unsupported combination")
		return data


class WriteFile(object):
	def __init__(self, path):
		self._file = None
		self._path = path
		self._startFrom = 0
		self._blockSize = 0
		self._data = bytearray(0)
	
	def Open(self):
		self._file = open(self._path, "r+b")
		self._file.seek(self._startFrom)
	
	def Close(self):
		self._WriteRemains()
		self._file.close()
	
	@property
	def StartFrom(self): return self._startFrom
	
	@StartFrom.setter
	def StartFrom(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._startFrom = value
	
	@property
	def BlockSize(self): return self._blockSize
	
	@BlockSize.setter
	def BlockSize(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._blockSize = value
	
	def _WriteRemains(self):
		''' write buffer remains data '''
		remains = len(self._data)
		if (remains == 0): return
		position = self._file.tell()
		toRead = self._file.read(self._blockSize)
		toWrite = bytearray(len(toRead))
		toWrite[0:remains] = self._data[0:len(self._data)]
		self._file.seek(position)
		self._file.write(toWrite)
	
	def _WriteAll(self, data):
		self._file.write(data)
	
	def _WriteBlock(self, data):
		self._data.extend(data)
		while (len(self._data) >= self._blockSize):
			self._file.write(self._data[0:self._blockSize])
			self._data = self._data[self._blockSize:]
	
	def Write(self, data):
		if (self._blockSize == 0):
			self._WriteAll(data)
		else:
			self._WriteBlock(data)


class ReadDevice(object):
	def __init__(self, volume):
		self._startFrom = 0
		self._blockSize = 0
		self._count = 0
		self._manager = DeviceManager()
		self._manager.VolumeExists(volume)
		self._device = self._manager.GetDeviceInfoByVolume(volume)
		self._path = self._device.Filename
		self._volumes = self._device.Volumes()
	
	def Open(self):
		self._file = open(self._path, "rb")
		self._file.seek(self._startFrom)
	
	def Close(self):
		self._file.close()
	
	@property
	def StartFrom(self): return self._startFrom
	
	@StartFrom.setter
	def StartFrom(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._startFrom = value
	
	@property
	def Count(self): return self._count
	
	@Count.setter
	def Count(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._count = value
	
	@property
	def BlockSize(self): return self._blockSize
	
	@BlockSize.setter
	def BlockSize(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._blockSize = value
		
	def _ReadAll(self):
		data = self._file.read()
		return data
	
	def _ReadBlock(self):
		data = self._file.read(self._blockSize)
		return data
	
	def Read(self):
		if (self._blockSize == 0):
			raise Exception("unsupported")
		else:
			data = self._ReadBlock()
		return data


class WriteDevice(object):
	def __init__(self, volume):
		self._file = None
		self._startFrom = 0
		self._position = 0
		self._blockSize = 0
		self._data = bytearray(0)
		self._manager = DeviceManager()
		self._manager.VolumeExists(volume)
		self._device = self._manager.GetDeviceInfoByVolume(volume)
		self._path = self._device.Filename
		self._volumes = [i for i in self._device.Volumes]
	
	@property
	def StartFrom(self): return self._startFrom
	
	@StartFrom.setter
	def StartFrom(self, value):
		value = str(value)
		value = value.upper()
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._startFrom = value
	
	@property
	def BlockSize(self): return self._blockSize
	
	@BlockSize.setter
	def BlockSize(self, value):
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		self._blockSize = value
	
	def _DismountVolumes(self):
		''' dismount all volumes of device, so raw write to device can proceed '''
		for volume in self._volumes:
			filename = self._manager.GetVolumeFilename(volume)
			handle = win32file.CreateFile(filename, win32file.GENERIC_WRITE | win32file.GENERIC_READ, win32file.FILE_SHARE_WRITE | win32file.FILE_SHARE_READ, None, win32file.OPEN_EXISTING, win32file.FILE_ATTRIBUTE_NORMAL, None)
			win32file.DeviceIoControl(handle, winioctlcon.FSCTL_DISMOUNT_VOLUME, '', 0, None)
			win32file.CloseHandle(handle)
	
	def Open(self):
		self._DismountVolumes()
		self._file = win32file.CreateFile(self._path, win32file.GENERIC_WRITE | win32file.GENERIC_READ, win32file.FILE_SHARE_WRITE | win32file.FILE_SHARE_READ, None, win32file.OPEN_EXISTING, win32file.FILE_ATTRIBUTE_NORMAL, None)
		if (self._file is None): raise Exception("Cannot open : {PATH} " . format(PATH=self._path))
		self._position = self._startFrom
		
	def Close(self):
		self._WriteRemains()
		win32file.CloseHandle(self._file)
	
	def _WriteRemains(self):
		''' write buffer remains data '''
		win32file.SetFilePointer(self._file, 0x400, win32file.FILE_BEGIN)
		data = win32file.ReadFile(self._file, 512, None)
		remains = len(self._data)
		if (remains == 0): return
		buffer = bytearray(self._blockSize)
		win32file.SetFilePointer(self._file, self._position, win32file.FILE_BEGIN)
		result = win32file.ReadFile(self._file, buffer, None)
		win32file.SetFilePointer(self._file, self._position, win32file.FILE_BEGIN)
		buffer[0:remains] = self._data[0:len(self._data)]
		win32file.WriteFile(self._file, buffer, None)
		
	def _WriteAll(self, data):
		self._file.write(data)
		
	def _WriteBlock(self, data):
		self._data.extend(data)
		while (len(self._data) >= self._blockSize):
			toWrite = self._data[0:self._blockSize]
			win32file.SetFilePointer(self._file, self._position, win32file.FILE_BEGIN)
			win32file.WriteFile(self._file, toWrite, None)
			self._position += self._blockSize
			self._data = self._data[self._blockSize:]
	
	def Write(self, data):
		if (self._blockSize >= 0):
			self._WriteBlock(data)
		else:
			raise Exception("Block size must be set")


class Application(object):
	def __init__(self):
		self._manager = DeviceManager()
		self._argv = CmdArguments()
		
	def _ActionInfo(self):
		''' print available volumes '''
		message = "\n"
		volumes = self._manager.GetVolumesName()
		if (volumes):
			message += "  Available volumes: {VOLUMES}".format(VOLUMES=" ".join(volumes))
		else:
			message += "  No volume available"
		print(message)
		
	def _ActionLicense(self):
		message  = '''
THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.
'''
		print(message)

	def _ActionHelp(self):
		''' print help message '''
		message = '''
WARNING: Utility REWRITES raw device data. MAKE A SURE you set right volume and offset.

usage: ddcopy.exe
  
  Print this help.


usage: ddcopy.exe --license
  
  Print license information.


usage: ddcopy.exe --info
  
  Print list of all available volumes.


usage: ddcopy.exe infile=<file_path> outdevice=<volume:> seek=<offset>
  
  infile=<file_path>    input image file
  outdevice=<volume:>   output volume, eg. f:
  seek=<offset>         volume device offset
  
  Copy input file to raw device (by it's volume) starting at device "seek" offset.
  Example: ddcopy.exe infile=bootloader_vybrid_twrvf65gs10_a5.imx outdevice=<your disk name:> seek=0x400
'''
		print(message)
	
	def _ActionCopy(self):
		print("start copying")
		source = None
		target = None
	# set input file|device
		if (self._argv.Exists('infile')):
			source = ReadFile(self._argv.Get('infile'))
		elif (self._argv.Exists('indevice')):
			source = ReadDevice(self._argv.Get('indevice'))
			# set 512 as default block size
			source.BlockSize = 512
		else:
			raise Exception("Missing 'infile' or 'indevice'")
	# set output file|device
		if (self._argv.Exists('outfile')):
			target = WriteFile(self._argv.Get('outfile'))
		elif (self._argv.Exists('outdevice')):
			target = WriteDevice(self._argv.Get('outdevice'))
			# set 512 as default block size
			target.BlockSize = 512
		else:
			raise Exception("Missing 'outfile' or 'outdevice'")
	# set seek
		if (self._argv.Exists('seek')): target.StartFrom = self._argv.Get('seek')
	# set skip
		if (self._argv.Exists('skip')): source.StartFrom = self._argv.Get('skip')
	# set block size
		if (self._argv.Exists('bs')):
			source.BlockSize = self._argv.Get('bs')
			target.BlockSize = self._argv.Get('bs')
		if (self._argv.Exists('ibs')):
			source.BlockSize = self._argv.Get('ibs')
		if (self._argv.Exists('obs')):
			target.BlockSize = self._argv.Get('obs')
	# perform copy
		source.Open()
		target.Open()
		data = source.Read()
		while (len(data) > 0):
			target.Write(data)
			data = source.Read()
		source.Close()
		target.Close()
		print("done")
	
	def Run(self):
		''' run application '''
		try:
			if (self._argv.Exists('--info') or self._argv.Exists('info')):
				self._ActionInfo()
			elif (
				(self._argv.Exists('infile') or self._argv.Exists('indevice')) and
				(self._argv.Exists('outfile') or self._argv.Exists('outdevice'))
			):
				self._ActionCopy()
			elif (self._argv.Exists('--license') or self._argv.Exists('license')):
				self._ActionLicense()
			else:
				self._ActionHelp()
		except Exception as error:
			print("Exception : " + str(error))

Application().Run()


