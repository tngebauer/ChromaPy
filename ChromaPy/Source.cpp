#include "Header/Keyboard.h"
#include "Header/Mouse.h"
#include "Header/Mousepad.h"
#include "Header/Keypad.h"
#include "Header/Headset.h"
#include "Header/Smart Home.h"

PyObject *SyntaxError;
Chroma_Implementation Chroma;
sf::TcpSocket TCP_SOCKET;
vector<Yeelight*> Bulbs;

PyObject* applyEffect(PyObject* self, PyObject* args) {

	Chroma.applyKeyboardEffect();
	Chroma.applyMouseEffect();
	Chroma.applyMousepadEffect();
	Chroma.applyKeypadEffect();
	Chroma.applyHeadsetEffect();

	return PyUnicode_FromString("Success");
}

PyObject* set_all(PyObject* self, PyObject* args)
{
	
	PyObject *Color;
	if(!PyArg_ParseTuple(args,"O",&Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setColor(color) | setColor( (R, G, B))");
		return nullptr;
	}
	
	COLORREF color;
	
	if (!Chroma.Colortest(Color, color)) {
		return PyUnicode_FromString("Invalid Arguments!Color needs to be(0 - 255, 0 - 255, 0 - 255)"); }
	Chroma.set_all(color);
	for (size_t i = 0; i < Bulbs.size(); i++) {
		Bulbs[i]->color(color);
	}
	Chroma.applyKeyboardEffect();
	Chroma.applyMouseEffect();
	Chroma.applyMousepadEffect();
	Chroma.applyKeypadEffect();
	Chroma.applyHeadsetEffect();
	return PyUnicode_FromString("Success");
}

PyObject* getconnected(PyObject* self, PyObject* args)
{
	vector<char*> devices;
	Chroma.ConnectedDevices(devices);

		PyObject *lst = PyList_New(devices.size());

		for(size_t i = 0; i < devices.size(); i++)
		{
			PyObject *str = PyUnicode_FromString(devices[i]);
			PyList_SET_ITEM(lst, i, str);
		}
		return lst;
}



PyObject* ResetEffect(PyObject* self, PyObject* args) {
	
	for (UINT device = 1; device < 6; device++) {
		Chroma.ResetEffects(device);
	}
	return PyUnicode_FromString("Success");

}

PyMethodDef ChromaPyMethods[] = { 
	
	{"setColor", static_cast<PyCFunction>(set_all), METH_VARARGS, docGlobalsetColor },
	{ "getConnectedDevices", static_cast<PyCFunction>(getconnected), METH_NOARGS, docGlobalgetConnectedDevices },
	{ "applyEffect", static_cast<PyCFunction>(applyEffect), METH_NOARGS, docGlobalapplyEffect },
	{"resetEffect",static_cast<PyCFunction>(ResetEffect), METH_NOARGS, docGlobalresetEffect },
	{nullptr,nullptr,0,nullptr}

};


static struct PyModuleDef ChromaPy = {
	PyModuleDef_HEAD_INIT,
	"ChromaPy",   /* name of module */
	docGlobal, /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
			  or -1 if the module keeps state in global variables. */
	ChromaPyMethods
};

PyMODINIT_FUNC
PyInit_ChromaPy()
{
	Chroma.Initialize();
	Keyboard_Type.tp_new = PyType_GenericNew;
	
	if (PyType_Ready(&Keyboard_Type) < 0) {
		return nullptr;
	}
	Mouse_Type.tp_new = PyType_GenericNew;
	if(PyType_Ready(&Mouse_Type) < 0)
	{
		return nullptr;
	}
	Mousepad_Type.tp_new = PyType_GenericNew;
	if(PyType_Ready(&Mousepad_Type) < 0)
	{
		return nullptr;
	}

	Keypad_Type.tp_new = PyType_GenericNew;
	if (PyType_Ready(&Keypad_Type) < 0)
	{
		return nullptr;
	}
	Headset_Type.tp_new = PyType_GenericNew;
	if (PyType_Ready(&Headset_Type)< 0)
	{
		return nullptr;
	}

	PyObject * m = PyModule_Create(&ChromaPy);
	if (m == nullptr) {
		return nullptr;
	}

	SmartHome_Type.tp_new = PyType_GenericNew;
	if (PyType_Ready(&SmartHome_Type)< 0)
	{
		return nullptr;
	}

	SyntaxError = PyErr_NewException("ChromaPy.SyntaxError", nullptr, nullptr);
	Py_INCREF(SyntaxError);
	PyModule_AddObject(m, "SyntaxError", SyntaxError);


	Py_INCREF(&Keyboard_Type);
	Py_INCREF(&Mouse_Type);
	Py_INCREF(&Mousepad_Type);
	Py_INCREF(&Keypad_Type);
	Py_INCREF(&Headset_Type);
	Py_INCREF(&SmartHome_Type);

	PyModule_AddObject(m, "Keyboard", reinterpret_cast<PyObject *>(&Keyboard_Type));
	PyModule_AddObject(m, "Mouse", reinterpret_cast<PyObject *>(&Mouse_Type));
	PyModule_AddObject(m, "Mousepad", reinterpret_cast<PyObject *>(&Mousepad_Type));
	PyModule_AddObject(m, "Keypad", reinterpret_cast<PyObject *>(&Keypad_Type));
	PyModule_AddObject(m, "Headset", reinterpret_cast<PyObject *>(&Headset_Type));
	PyModule_AddObject(m, "SmartHome", reinterpret_cast<PyObject *>(&SmartHome_Type));
	return m;
}

//Currently 2475 lines of Code