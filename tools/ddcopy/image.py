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
* $FileName: image.py$
* $Version : 3.8.6.0$
* $Date    : Oct-3-2012$
*
*END************************************************************************/
'''


import re
import sys
import struct
import binascii
from elftools.elf import elffile


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

class BinaryApplication(object):
	''' represent settings of application binary file '''
	def __init__(self):
		self._entryAddress = None
		self._baseAddress = None
		self._offset = 0
		self._binaryData = []
	
	def _Conv2Long(self, value):
		''' convert string into long type '''
		value = str(value)
		result = (re.match('^0x([0-9a-f]+)$', value, re.IGNORECASE))
		value = long(result.group(1), 16) if result else long(value)
		return value 
	
	@staticmethod
	def FromBin(params):
		''' ioc, create ApplicationBinary instance from .bin '''
		for required in ['addr_mem', 'addr_header', 'addr_base', 'addr_entry']:
			if (not(required in params)):
				raise Exception("Missing argument '{ARGUMENT}'".format(ARGUMENT=required))
		instance = BinaryApplication()
		instance._MemoryAddress = params['addr_mem']
		instance._BaseAddress = params['addr_base']
		instance._EntryAddress = params['addr_entry']
		instance._HeaderAddress = params['addr_header']
		with open(params['path'], "rb") as file: instance._binaryData = file.read()
		return instance
	
	@staticmethod
	def FromElf(params):
		''' ioc, create ApplicationBinary instance from file .elf '''
	# open a stream
		file = open(params['path'], "rb")
		elf = elffile.ELFFile(file)
	# set attributes
		instance = BinaryApplication()
		instance._MemoryAddress = params['addr_mem']
		instance._BaseAddress = params['addr_base']
		instance._HeaderAddress = params['addr_header']
		instance._EntryAddress = elf.header.e_entry
		data = bytearray(0)
		segments = [i for i in elf.iter_segments()]
	# calculate lowest address
		lowest = None
		for segment in segments:
			if (lowest is None): lowest = segment.header.p_vaddr
			if (lowest > segment.header.p_vaddr): lowest = segment.header.p_vaddr
	# calculate segment
		for segment in segments:
			position = segment.header.p_vaddr - lowest
			size = segment.header.p_memsz
		# resize data buffer
			resize = (position + size) - (len(data))
			if (resize > 0): data.extend([0] * resize)
			data[position:position + size] = segment.data()
		instance._binaryData = data
		file.close()
		return instance
	
	@property
	def EntryAddress(self): return self._entryAddress
	@EntryAddress.setter
	def _EntryAddress(self, value):
		value = self._Conv2Long(value)
		if (value.bit_length() > 32):
			raise Exception("Entry address '{ADDRESS}' is out 32 bit range" . format(ADDRESS=value))
		self._entryAddress = value
	
	@property
	def MemoryAddress(self): return self._memoryAddress
	@MemoryAddress.setter
	def _MemoryAddress(self, value):
		value = self._Conv2Long(value)
		if (value.bit_length() > 32):
			raise Exception("Memory address '{ADDRESS}' is out 32 bit range" . format(ADDRESS=value))
		self._memoryAddress = value
	
	@property
	def BaseAddress(self): return self._baseAddress
	@BaseAddress.setter
	def _BaseAddress(self, value):
		value = self._Conv2Long(value)
		if (value.bit_length() > 32):
			raise Exception("Base address '{ADDRESS}' is out 32 bit range" . format(ADDRESS=value))
		self._baseAddress = value
	
	@property
	def HeaderAddress(self): return self._headerAddress
	@BaseAddress.setter
	def _HeaderAddress(self, value):
		value = self._Conv2Long(value)
		if (value.bit_length() > 32):
			raise Exception("Header address '{ADDRESS}' is out 32 bit range" . format(ADDRESS=value))
		self._headerAddress = value
	
	def tobytes(self):
		if (self._entryAddress is None): raise Exception("Entry address is not set")
		if (self._baseAddress is None): raise Exception("Base address is not set")
		if (self._baseAddress is None): raise Exception("Base address is not set")
		return self._binaryData


class Image(object):
	class ImageVectorTable(object):
		'''' image vector table structure '''
		def __init__(self):
			self._headerTag = 0xd1
			self._headerLength = 0x20
			self._headerVersion = 0x41
			self._entryAddress = 0x0
			self._dcdAddress = 0x0
			self._bootAddress = 0x0
			self._ivtAddress = 0x0
			self._csfAddress = 0x0
		def tobytes(self):
			''' convert object into binary sequence '''
			data = bytearray(0)
		# 4B, ivt header, big endian
			data.extend(struct.pack(">BHB", self._headerTag, self._headerLength, self._headerVersion))
		# 4B, entry address, little endian
			data.extend(struct.pack("<L", self._entryAddress))
		# 4B, reserved, little endian
			data.extend(struct.pack("<L", 0))
		# 4B, dcd address, little endian
			data.extend(struct.pack("<L", self._dcdAddress))
		# 4B, boot data address, little endian
			data.extend(struct.pack("<L", self._bootAddress))
		# 4B, ivt address, little endian
			data.extend(struct.pack("<L", self._ivtAddress))
		# 4B, csf address, little endian
			data.extend(struct.pack("<L", self._csfAddress))
		# 4B, reserved, little endian
			data.extend(struct.pack("<L", 0))
			return data
		@property
		def HeaderTag(self): return self._tag
		@property
		def HeaderVersion(self): return self._version
		@property
		def HeaderLength(self): return self._length
		@property
		def EntryAddress(self): return self._entryAddress
		@EntryAddress.setter
		def EntryAddress(self, value): self._entryAddress = long(value)
		@property
		def DcdAddress(self): return self._dcdAddress
		@DcdAddress.setter
		def DcdAddress(self, value): self._dcdAddress = long(value)
		@property
		def BootAddress(self): return self._bootAddress
		@BootAddress.setter
		def BootAddress(self, value): self._bootAddress = long(value)
		@property
		def IvtAddress(self): return self._ivtAddress
		@IvtAddress.setter
		def IvtAddress(self, value): self._ivtAddress = long(value)
		@property
		def CsfAddress(self): return self._csfAddress
		@CsfAddress.setter
		def CsfAddress(self, value): self._csfAddress = long(value)
	
	class BootDataStructure(object):
		'''' boot structure '''
		def __init__(self):
			self._startAddress = 0x0
			self._length = 0x0
			self._plugin = 0x0
		def tobytes(self):
			data = bytearray(0)
		# 4B, startAddress
			data.extend(struct.pack("<L", self._startAddress))
		# 4B, length
			data.extend(struct.pack("<L", self._length))
		# 4B, _plugin
			data.extend(struct.pack("<L", self._plugin))
			return data
		@property
		def StartAddress(self): return self._startAddress
		@StartAddress.setter
		def StartAddress(self, value): self._startAddress = value
		@property
		def Length(self): return self._length
		@Length.setter
		def Length(self, value): self._length = value
		@property
		def Plugin(self): return self._plugin
		@Plugin.setter
		def Plugin(self, value): self._plugin = value
	
	class DeviceConfigData(object):
		'''' dcd structure '''
		def __init__(self):
			self._headerTag = 0xD2
			self._headerLength = 0x0
			self._headerVersion = 0x40
		def tobytes(self):
			data = bytearray(0)
			self._headerLength = 0x8
		# 4B, header
			data.extend(struct.pack(">BHB", self._headerTag, self._headerLength, self._headerVersion))
			data.extend(struct.pack("<L", 0x040400CC))
			return data
		@property
		def HeaderTag(self): return self._headerTag
		@property
		def HeaderLength(self): return self._headerLength
		@property
		def HeaderVersion(self): return self._headerVersion
	
	def __init__(self, appBinary):
		''' initialiser '''
		self._appBinary = appBinary
		if (not(
			self._appBinary.MemoryAddress < 
			self._appBinary.HeaderAddress < 
			self._appBinary.BaseAddress <= 
			self._appBinary.EntryAddress
		)):
			message = "Addresses doesn't match order: {MEMORY_ADDRESS} < {HEADER_ADDRESS} < {BASE_ADDRESS} <= {ENTRY_ADDRESS}"
			message.format(
				MEMORY_ADDRESS=hex(self._appBinary.MemoryAddress),
				HEADER_ADDRESS=hex(self._appBinary.HeaderAddress),
				BASE_ADDRESS=hex(self._appBinary.BaseAddress),
				ENTRY_ADDRESS=hex(self._appBinary.EntryAddress),
			);
			raise Exception(message)
		
		self._ivt = Image.ImageVectorTable()
		self._boot = Image.BootDataStructure()
		self._dcd = Image.DeviceConfigData()
		self._sectorSize = 0x200
	
	def tobytes(self):
		''' convert image to bytes and solve referencies '''
		resultData = bytearray(0)
		offsets = {}
	# get ivt data & offsets
		offsets['ivt-begin'] = len(resultData)
		data = self._ivt.tobytes()
		resultData.extend(data)
		offsets['ivt-end'] = len(resultData)
	# get boot data & offsets
		offsets['boot-begin'] = len(resultData)
		data = self._boot.tobytes()
		resultData.extend(data)
		offsets['boot-end'] = len(resultData)
	# get dcd data & offsets
		offsets['dcd-begin'] = len(resultData)
		data = self._dcd.tobytes()
		resultData.extend(data)
		offsets['dcd-end'] = len(resultData)
	# create zero fill gap between header and application data
		gapSize = (self._appBinary.BaseAddress - self._appBinary.HeaderAddress) - len(resultData)
		resultData.extend(bytearray(gapSize))
	# get app data & offsets
		data = self._appBinary.tobytes()
		offsets['app-begin'] = len(resultData)
		resultData.extend(data)
		offsets['app-end'] = len(resultData)
	# calculate/modify address
		address = {}
		address['ivt_app'] = self._appBinary.EntryAddress
		address['ivt_ivt'] = self._appBinary.HeaderAddress
		address['ivt_dcd'] = self._appBinary.HeaderAddress + offsets['dcd-begin']
		address['ivt_boot'] = self._appBinary.HeaderAddress + offsets['boot-begin']
		address['boot_start'] = self._appBinary.MemoryAddress
	# set size of program image
		length = len(resultData) + (self._appBinary.HeaderAddress - self._appBinary.MemoryAddress)
		length = long((length + self._sectorSize - 1) / self._sectorSize)
		length = length * self._sectorSize
		
		self._boot.Length = length
		self._ivt.IvtAddress = address['ivt_ivt']
		self._ivt.BootAddress = address['ivt_boot']
		self._ivt.CsfAddress = 0x0
		self._ivt.EntryAddress = address['ivt_app']
		self._ivt.DcdAddress = address['ivt_dcd']
		self._boot.StartAddress = address['boot_start']
	# recreate modified data
		resultData[offsets['ivt-begin']:offsets['ivt-end']] = self._ivt.tobytes()
		resultData[offsets['boot-begin']:offsets['boot-end']] = self._boot.tobytes()
		resultData[offsets['app-begin']:offsets['app-end']] = self._appBinary.tobytes()
		resultData[offsets['dcd-begin']:offsets['dcd-end']] = self._dcd.tobytes()
		return resultData


class Application(object):
	def __init__(self):
		self._argv = CmdArguments()
	
	def _ActionBin(self):
		''' create image from .bin file '''
		for required in ['bin', 'addr_entry', 'addr_mem', 'addr_header', 'addr_base']:
			if (not self._argv.Exists(required)):
				raise Exception("Missing argument '{ARGUMENT}'".format(ARGUMENT=required))
		app = BinaryApplication.FromBin({
			'path' 			: self._argv.Get('bin'),
			'addr_mem'		: self._argv.Get('addr_mem'),
			'addr_header'	: self._argv.Get('addr_header'),
			'addr_base'		: self._argv.Get('addr_base'),
			'addr_entry'	: self._argv.Get('addr_entry'),
		})
		image = Image(app)
		path = self._argv.Get('image')
		with open(path, "wb") as file: file.write(image.tobytes())
	
	def _ActionElf(self):
		''' create image from .elf file, entry is parsed from elf '''
		for required in ['elf', 'addr_mem', 'addr_header', 'addr_base']:
			if (not self._argv.Exists(required)):
				raise Exception("Missing argument '{ARGUMENT}'".format(ARGUMENT=required))
		app = BinaryApplication.FromElf({
			'path' 			: self._argv.Get('elf'),
			'addr_mem'		: self._argv.Get('addr_mem'),
			'addr_header'	: self._argv.Get('addr_header'),
			'addr_base'		: self._argv.Get('addr_base'),
		})
		image = Image(app)
		path = self._argv.Get('image')
		with open(path, "wb") as file: file.write(image.tobytes())
	
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
usage: image.exe
  
  Print this help.


usage: image.exe --license
  
  Print license information.


usage: image.exe bin=<file_path> addr_mem=<address> addr_header=<address> addr_base=<address> addr_entry=<address> image=<file_path>
  
  bin=<file_path>           - input binary application
  addr_mem=<address>        - start of SRAM bank where the bootloader program is located
  addr_header=<address>     - IVT header SRAM addres = addr_mem + 0x400
  addr_base=<address>       - start SRAM address of compiled bootloader image
  addr_entry=<address>      - SRAM address of entry point (e.g __ICFEDIT_intvec_start__)
  image=<file_path>         - output image file for Vybrid BootROM in SDCARD format

  Create ROM bootloader image file from application binary file.
  Example: image.exe bin=bootloader_vybrid_twrvf65gs10_a5.bin addr_mem=0x3f040000 addr_header=0x3f040400 addr_base=0x3f050800 addr_entry=0x3f050800 image=bootloader_vybrid_twrvf65gs10_a5.imx
'''
		print(message)
	
	def Run(self):
		''' run application '''
		try:
			if (self._argv.Exists('bin')):
				print("creating image ")
				self._ActionBin()
				print("done")
			elif (self._argv.Exists('elf')):
				print("creating image ")
				self._ActionElf()
				print("done")
			elif (self._argv.Exists('--license') or self._argv.Exists('license')):
				self._ActionLicense()
			else:
				self._ActionHelp()
		except Exception as error:
			print("Exception : " + str(error))

Application().Run()


