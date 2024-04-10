from setuptools import setup, Extension
import glob

sources_files = glob.glob('./readline_py/*.c')

module = Extension('my_readline_module',
                    sources = sources_files,
                    include_dirs = ['./readline_py/my_readline.h'],  
                    libraries = [], 
                    library_dirs = [])

setup(name = 'MyReadlineModule',
      version = '1.01',
      description = 'Python interface for custom readline C function',
      ext_modules = [module])