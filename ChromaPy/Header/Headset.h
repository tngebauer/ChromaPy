#pragma once
#include "ChromaSDK.h"

typedef struct
{
	PyObject_HEAD
		long MaxLED;


} ChromaHeadset;

static PyMemberDef headsetmembers[] = {

	{ "MaxLED", T_INT, offsetof(ChromaHeadset , MaxLED), READONLY, docHeadsetLED },
	{nullptr }  /* Sentinel */
};

PyObject* set_headset(PyObject* self, PyObject* args);

PyObject* set_headsetbyled(PyObject* self, PyObject* args);

PyObject* clear_headset(PyObject* self, PyObject* args);

PyObject* applyEffectHeadset(PyObject* self, PyObject* args);

PyObject* ResetEffectHeadset(PyObject* self, PyObject* args);

PyObject* BreathingEffectHeadset(PyObject* self, PyObject* args);


static PyMethodDef headsetmethods[] = {
	{ "setColor", static_cast<PyCFunction>(set_headset), METH_VARARGS, docHeadsetsetColor },
	{ "setbyLED", static_cast<PyCFunction>(set_headsetbyled), METH_VARARGS, docHeadsetsetbyCord },
	{ "setBreathing", static_cast<PyCFunction>(BreathingEffectHeadset), METH_VARARGS, docHeadsetsetBreathing },
	{ "clearLED", static_cast<PyCFunction>(clear_headset), METH_NOARGS, docHeadsetclearEffect },
	{ "applyLED", static_cast<PyCFunction>(applyEffectHeadset), METH_NOARGS, docHeadsetapply },
	{ "resetEffect", static_cast<PyCFunction>(ResetEffectHeadset), METH_NOARGS, docHeadsetresetEffect },
	{ nullptr,nullptr,0,nullptr }
};

int Headset_init(ChromaHeadset *self, PyObject *args, PyObject *kwds);


static PyTypeObject Headset_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Headset",             /* tp_name */
	sizeof(ChromaHeadset),             /* tp_basicsize */
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
	docHeadset,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	headsetmethods,             /* tp_methods */
	headsetmembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(Headset_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

