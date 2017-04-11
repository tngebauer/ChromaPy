#pragma once
#include "ChromaSDK.h"
//extern vector<Yeelight> Lights;
typedef struct
{
	PyObject_HEAD
} Yee_Bulb;

static PyMemberDef yeemembers[] = {
	{ nullptr }  /* Sentinel */
};


PyObject* add_light(PyObject* self, PyObject* args) {
	PyObject *IP,*Name;
	if (!PyArg_ParseTuple(args, "uu", &IP, &Name))
	{
		return 0;
	}
	string ip = PyUnicode_AsUTF8(IP);
	string name = PyUnicode_AsUTF8(Name);
	//Lights.push_back(Yeelight(ip,name));
	//ize_t position = Lights.size() - 1;
	string retour = "Successful, the Yeelight was saved as ";
	retour.append(name);
	retour.append(" with the ID ");
	//retour.append(to_string(position));
	return PyUnicode_FromString(retour.c_str());
}



static int yee_init(Yee_Bulb *self, PyObject *args, PyObject *kwds)
{
	return 0;
}

PyObject* power(PyObject* self, PyObject* args) {
	PyObject *state;
	size_t position;
	if (!PyArg_ParseTuple(args, "ui", &state,&position))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setColor(color) | setColor((R, G, B))");
		return nullptr;
	}



	string temp = PyUnicode_AsUTF8(state);
	//Lights[position].power(temp);
	return PyUnicode_FromString("Successful, I hope!");
}



static PyMethodDef yeemethods[] = {
	{ "power", power, METH_VARARGS, docMousepadsetColor },
	{ nullptr,nullptr,0,nullptr }
};


static PyTypeObject Yee_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Mouse",             /* tp_name */
	sizeof(Yee_Bulb),             /* tp_basicsize */
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
	nullptr,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	yeemethods,             /* tp_methods */
	yeemembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(yee_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};
