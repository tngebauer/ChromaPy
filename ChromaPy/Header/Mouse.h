#pragma once
#include "ChromaSDK.h"


typedef struct
{
	PyObject_HEAD
		long MaxRow;
	long MaxColumn;
	long MaxLED;


} ChromaMouse;

static PyMemberDef mousemembers[] = {

	{ "MaxRow", T_INT, offsetof(ChromaMouse , MaxRow), READONLY, docMouseMaxRow },
	{ "MaxColumn", T_INT, offsetof(ChromaMouse , MaxColumn), READONLY, docMouseMaxColumn },
	{ "MaxLED", T_INT, offsetof(ChromaMouse , MaxLED), READONLY, docMouseMaxLED },
	{nullptr }  /* Sentinel */
};

PyObject* set_mouse(PyObject* self, PyObject* args);


PyObject* set_mousebycord(PyObject* self, PyObject* args);

PyObject* set_mousebyrow(PyObject* self, PyObject* args);

PyObject* set_mousebycol(PyObject* self, PyObject* args);

PyObject* clear_mouse(PyObject* self, PyObject* args);

PyObject* applyEffectMouse(PyObject* self, PyObject* args);

PyObject* ResetEffectMouse(PyObject* self, PyObject* args);

PyObject*WaveEffectMouse(PyObject* self, PyObject* args);

PyObject* BreathingEffectMouse(PyObject* self, PyObject* args);


static PyMethodDef mousemethods[] = {
	{ "setColor", static_cast<PyCFunction>(set_mouse), METH_VARARGS, docMousesetColor },
	{ "setbyGrid", static_cast<PyCFunction>(set_mousebycord), METH_VARARGS, docMousesetbyCord },
	{ "setbyRow", reinterpret_cast<PyCFunction>(set_mousebyrow), METH_VARARGS, docMousesetbyRow },
	{ "setbyCol", reinterpret_cast<PyCFunction>(set_mousebycol), METH_VARARGS, docMousesetbyCol },
	{ "setBreathing", static_cast<PyCFunction>(BreathingEffectMouse), METH_VARARGS, docHeadsetsetBreathing},
	{ "setWave", static_cast<PyCFunction>(WaveEffectMouse), METH_VARARGS, docKeypadsetWave },
	{ "clearGrid", reinterpret_cast<PyCFunction>(clear_mouse), METH_NOARGS, docMouseclearEffect },
	{ "applyGrid", static_cast<PyCFunction>(applyEffectMouse), METH_NOARGS, docMouseapply },
	{ "resetEffect", static_cast<PyCFunction>(ResetEffectMouse), METH_NOARGS, docMouseresetEffect },
	{ nullptr,nullptr,0,nullptr }
};

static int Mouse_init(ChromaMouse *self, PyObject *args, PyObject *kwds)
{

	self->MaxRow = Chroma.Mouse_MaxRow();
	self->MaxColumn = Chroma.Mouse_MaxCol();
	self->MaxLED = Chroma.Mouse_MaxLED();
	return 0;
}

static PyTypeObject Mouse_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Mouse",             /* tp_name */
	sizeof(ChromaMouse),             /* tp_basicsize */
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
	docMouse,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	mousemethods,             /* tp_methods */
	mousemembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(Mouse_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

