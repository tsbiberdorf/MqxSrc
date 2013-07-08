from distutils.core import setup
import py2exe, sys, os
sys.argv.append('py2exe')


setup(
	options = {'py2exe': { 
		'bundle_files'	: 1,
		'includes'		: ['win32api'],
		'dll_excludes'	: [ "mswsock.dll", "powrprof.dll" ]
	}},
	console = [{'script': "image.py"}],
	zipfile = None,
)



setup(
	options = {'py2exe': { 
		'bundle_files'	: 1,
		'includes'		: ['win32api'],
		'dll_excludes'	: [ "mswsock.dll", "powrprof.dll" ]
	}},
	console = [{'script': "ddcopy.py"}],
	zipfile = None,
)


