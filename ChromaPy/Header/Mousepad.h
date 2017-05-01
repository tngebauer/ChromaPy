#pragma once
#include "ChromaSDK.h"

typedef struct
{
	PyObject_HEAD
		long MaxLED;


} ChromaMousepad;

static PyMemberDef mousepadmembers[] = {

	{ "MaxLED", T_INT, offsetof(ChromaMousepad , MaxLED), READONLY, docMousepadLED },
	{nullptr }  /* Sentinel */
};

PyObject* set_mousepad(PyObject* self, PyObject* args);

PyObject* set_mousepadbyled(PyObject* self, PyObject* args);

PyObject* clear_mousepad(PyObject* self, PyObject* args);

PyObject* applyEffectMousepad(PyObject* self, PyObject* args);

PyObject* ResetEffectMousepad(PyObject* self, PyObject* args);

PyObject*WaveEffectMousepad(PyObject* self, PyObject* args);

PyObject* BreathingEffectMousepad(PyObject* self, PyObject* args);


static PyMethodDef mousepadmethods[] = {
	{ "setColor", static_cast<PyCFunction>(set_mousepad), METH_VARARGS, docMousepadsetColor },
	{ "setbyLED", static_cast<PyCFunction>(set_mousepadbyled), METH_VARARGS, docMousepadsetbyCord },
	{ "setWave", static_cast<PyCFunction>(WaveEffectMousepad), METH_VARARGS, docMousepadsetWave },
	{ "setBreathing", static_cast<PyCFunction>(BreathingEffectMousepad), METH_VARARGS, docHeadsetsetBreathing },
	{ "clearLED", static_cast<PyCFunction>(clear_mousepad), METH_NOARGS, docMousepadclearEffect },
	{ "applyLED", static_cast<PyCFunction>(applyEffectMousepad), METH_NOARGS, docMousepadapply },
	{ "resetEffect", static_cast<PyCFunction>(ResetEffectMousepad), METH_NOARGS, docMousepadresetEffect },
	{ nullptr,nullptr,0,nullptr }
};

static int Mousepad_init(ChromaMousepad *self, PyObject *args, PyObject *kwds)
{

	self->MaxLED = Chroma.Mousepad_MaxLED();
	return 0;
}

static PyTypeObject Mousepad_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Mousepad",             /* tp_name */
	sizeof(ChromaMousepad),             /* tp_basicsize */
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
	mousepadmethods,             /* tp_methods */
	mousepadmembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(Mousepad_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

