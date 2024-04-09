#include <Python.h>
#include "my_readline.h"

static PyObject* py_my_readline(PyObject* self, PyObject* args)
{
    int fd;
    if (!PyArg_ParseTuple(args, "i", &fd))
    {
        return NULL;
    }
    if (rl_buff == NULL) //unlikely to work but let's try to compile and run first
    { 
        init_my_readline();
    }
    char* result = my_readline(fd);
    if (result == NULL)
    {
        Py_RETURN_NONE;
    }
    PyObject* ret = PyUnicode_FromString(result);
    free(result);
    return ret;
}

static PyMethodDef MyReadlineMethods[] = {
    {"my_readline", py_my_readline, METH_VARARGS, "Read a line from fd."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myreadlinemodule = {
    PyModuleDef_HEAD_INIT,
    "my_readline_module", 
    NULL, 
    -1, 
    MyReadlineMethods
};

PyMODINIT_FUNC PyInit_my_readline_module(void)
{
    return PyModule_Create(&myreadlinemodule);
}