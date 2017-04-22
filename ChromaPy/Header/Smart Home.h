#pragma once
#include "Header/ChromaSDK.h"


typedef struct
{
	PyObject_HEAD
		Yeelight Bulb;

} SmartHome;


static PyMemberDef smarthomemembers[] = {
	{ nullptr }  /* Sentinel */
};


extern vector<Yeelight*> Bulbs;

PyObject* set_color(SmartHome *self, PyObject *args);

PyObject* set_ip(SmartHome *self, PyObject *args);

PyObject* power(SmartHome *self, PyObject *args);

PyObject* brightness(SmartHome *self, PyObject *args);

PyObject* getbrightness(SmartHome *self, PyObject *args);

PyObject* getrgb(SmartHome *self, PyObject *args);

PyObject* getpower(SmartHome *self, PyObject *args);




static PyMethodDef smarthomemethods[] = {
	{ "setColor", reinterpret_cast<PyCFunction>(set_color), METH_VARARGS, PlaceHolder },
	{ "setIP", reinterpret_cast<PyCFunction>(set_ip), METH_VARARGS, PlaceHolder },
	{ "setPower", reinterpret_cast<PyCFunction>(power), METH_VARARGS, PlaceHolder },
	{ "setBrightness", reinterpret_cast<PyCFunction>(brightness), METH_VARARGS, PlaceHolder },
	{ "getBrightness", reinterpret_cast<PyCFunction>(getbrightness), METH_NOARGS, PlaceHolder },
	{ "getRGB", reinterpret_cast<PyCFunction>(getrgb), METH_NOARGS, PlaceHolder },
	{ "getPower", reinterpret_cast<PyCFunction>(getpower), METH_NOARGS, PlaceHolder },
	{ nullptr,nullptr,0,nullptr }
};


static int smarthome_init(SmartHome *self, PyObject *args, PyObject *kwds)
{
	char* IP;
	if (!PyArg_ParseTuple(args, "s", &IP))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: SmartHome(IP))");
		return 1;
	}
	
	self->Bulb.changeip(IP);

	bool generate = true;
	for (size_t i = 0; i < Bulbs.size(); i++) {
		if (*Bulbs[i] == self->Bulb) {
			Bulbs.erase(Bulbs.begin() + i-1);
		}
	}
	Bulbs.push_back(&self->Bulb);
	return 0;
}




static PyTypeObject SmartHome_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"SmartHome",             /* tp_name */
	sizeof(SmartHome),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	nullptr, /* tp_dealloc */
	nullptr,                         /* tp_print */
	nullptr,                         /* tp_getattr */
	nullptr,                         /* tp_setattr */
	nullptr,                         /* tp_reserved */
	nullptr,                         /* tp_repr */
	nullptr,                         /* tp_as_number */
	nullptr,                         /* tp_as_sequence */
	nullptr,                         /* tp_as_mapping */
	nullptr,                         /* tp_hash  */
	nullptr,                         /* tp_call */
	nullptr,                         /* tp_str */
	nullptr,                         /* tp_getattro */
	nullptr,                         /* tp_setattro */
	nullptr,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	docMousepad,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	smarthomemethods,             /* tp_methods */
	smarthomemembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(smarthome_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

