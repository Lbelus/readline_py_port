from setuptools import setup, Extension

module = Extension('my_readline_module',
                    sources = ['my_readline_module.c'],
                    include_dirs = ['/path/to/headers'],  
                    libraries = [], 
                    library_dirs = [])

setup(name = 'MyReadlineModule',
      version = '1.0',
      description = 'Python interface for custom readline C function',
      ext_modules = [module])