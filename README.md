# readline_py_port
Port in python of a C implementation of readline

### How to install 

Documentation :
https://docs.python.org/3/extending/extending.html

To build and install image : 
```bash
docker build -t img_py_port .
docker run -it -v /pathToDir/:/workspace/ --name cont_py_port img_py_port /bin/bash
```

Create a virtual env
```bash
python3 -m venv myportenv-env
source myportenv-env/bin/activate
```

To build and install project 
```bash
python3 setup.py build
python3 setup.py install
```


### case usage 

You can read from any FD meaning a socket as well:
```python
import my_readline_module

my_readline_module.init_my_readline()
fd = open('myfile.txt', 'r')

line = None

while (line := my_readline_module.my_readline(fd.fileno())) is not None:
    print(line)

fd.close()
```

Meaning You can read from STDIN and pair my_readline with an strtok equivalent (.split()) if you intent to build a CLI: 

```python
import my_readline_module

my_readline_module.init_my_readline()

line = None

while (line := my_readline_module.my_readline(0)) is not None:
    tokens = line.split()
    print(tokens)
```
### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer