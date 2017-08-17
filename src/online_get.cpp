#include <vector>
#include <cmath>
#include <string>
#include <Python.h>
#include <iostream>


//    receive a vector with string for parameter
void online_get_invoice(std::vector<std::string> &vec){


	Py_Initialize();

/*
    import the python module by name
    and find function in this module
*/
	PyObject *pModule = PyImport_Import(PyString_FromString("invoice"));
	PyObject *pFunc = PyObject_GetAttrString(pModule, "online_get_invoice");

/*
    if it could be called, call it.
    and release the "pArgs" Object

    if returning is completed , it would return a python list
    and push per element of python list into vector

    if any section has error, will break the process and print error messages
*/
	if(pFunc && PyCallable_Check(pFunc)){

        PyObject *pArgs = PyTuple_New(0);
		PyObject *pReturn = PyObject_CallObject(pFunc, pArgs);
		Py_DECREF(pArgs);

		if(pReturn != NULL){

			for(Py_ssize_t i = 0; i < PyList_Size(pReturn); i++){

				 vec.push_back(std::string(PyString_AsString(PyList_GetItem(pReturn, i))));
			}

			Py_DECREF(pReturn);
		}
		else{

			Py_DECREF(pFunc);
			Py_DECREF(pModule);
			PyErr_Print();
			std::cerr << "CALL FAILED" << std::endl;
			return;
		}
	}
	else{

		if(PyErr_Occurred()) PyErr_Print();
		std::cerr << "Cannot find function";
	}

	return;
}
