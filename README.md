# readline_py_port
Port in python of a C implementation of readline

Documentation :
https://docs.python.org/3/extending/extending.html

To build and install image : 
```bash
docker build -t img_py_port .
docker run -it -v /pathToDir/:/workspace/ --name cont_py_port img_py_port /bin/bash
```

To build and install project 
```bash
python3 setup.py build
python3 setup.py install
```