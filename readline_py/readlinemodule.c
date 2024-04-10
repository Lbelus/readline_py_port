#include <Python.h>
#include "my_readline.h"



static PyObject* py_init_my_readline(PyObject* self, PyObject* args)
{
    char* result = init_my_readline();
    if (result == NULL)
    {
        Py_RETURN_NONE;
    }
    PyObject* ret = PyBytes_FromString(result);
    return ret;
}


static PyObject* py_my_readline(PyObject* self, PyObject* args)
{
    int fd;
    if (!PyArg_ParseTuple(args, "i", &fd))
    {
        return NULL;
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
    {"init_my_readline", py_init_my_readline, METH_NOARGS, "Initialize buffer."},
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