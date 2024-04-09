from setuptools import setup, Extension

module = Extension('my_readline_module',
                    sources = ['./readline_py/readlinemodule.c'],
                    include_dirs = ['./readline_py/'],  
                    libraries = [], 
                    library_dirs = [])

setup(name = 'MyReadlineModule',
      version = '1.0',
      description = 'Python interface for custom readline C function',
      ext_modules = [module])