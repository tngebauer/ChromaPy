#pragma once
#include "ChromaSDK.h"

typedef struct
{
	PyObject_HEAD
	long MaxRow;
	long MaxColumn;
	long MaxLED;


} ChromaKeypad;

static PyMemberDef keypadmembers[] = {

	{ "MaxRow", T_INT, offsetof(ChromaKeypad, MaxRow), READONLY, docKeypadMaxRow},
	{ "MaxColumns", T_INT, offsetof(ChromaKeypad, MaxColumn), READONLY, docKeypadMaxColumn },
	{ "MaxLED", T_INT, offsetof(ChromaKeypad, MaxLED), READONLY, docKeypadMaxLED },
	{nullptr }  /* Sentinel */
};

PyObject* set_keypad(PyObject* self, PyObject* args);

PyObject* set_keypadbycord(PyObject* self, PyObject* args);

PyObject* set_keypadbyrow(PyObject* self, PyObject* args);

PyObject* set_keypadbycol(PyObject* self, PyObject* args);

PyObject* clear_keypad(PyObject* self, PyObject* args);

PyObject* applyEffectKeypad(PyObject* self, PyObject* args);

PyObject* ResetEffectKeypad(PyObject* self, PyObject* args);

PyObject*ReactiveEffectKeypad(PyObject* self, PyObject* args);

PyObject*WaveEffectKeypad(PyObject* self, PyObject* args);

PyObject* BreathingEffectKeypad(PyObject* self, PyObject* args);

static PyMethodDef KeypadMethods[] = {
	{ "setColor", static_cast<PyCFunction>(set_keypad), METH_VARARGS, docKeypadsetColor },
	{ "setbyGrid", static_cast<PyCFunction>(set_keypadbycord), METH_VARARGS, docKeypadsetbyCord },
	{ "setbyCol", static_cast<PyCFunction>(set_keypadbycol), METH_VARARGS, docKeypadsetbyCol },
	{ "setbyRow", static_cast<PyCFunction>(set_keypadbyrow), METH_VARARGS, docKeypadsetbyRow },
	{ "setReactive", static_cast<PyCFunction>(ReactiveEffectKeypad), METH_VARARGS, docKeypadsetReactive },
	{ "setBreathing", static_cast<PyCFunction>(BreathingEffectKeypad), METH_VARARGS, docHeadsetsetBreathing },
	{ "setWave", static_cast<PyCFunction>(WaveEffectKeypad), METH_VARARGS, docKeypadsetWave },
	{ "clearGrid", static_cast<PyCFunction>(clear_keypad), METH_NOARGS, docKeypadclearEffect },
	{ "applyGrid", static_cast<PyCFunction>(applyEffectKeypad), METH_NOARGS, docKeypadapply},
	{ "resetEffect", static_cast<PyCFunction>(ResetEffectKeypad), METH_NOARGS, docKeypadresetEffect },
	{ nullptr,nullptr,0,nullptr }



};

static int Keypad_init(ChromaKeypad *self, PyObject *args, PyObject *kwds)
{

	self->MaxRow = Chroma.Keypad_MaxRow();
	self->MaxColumn = Chroma.Keypad_MaxCol();
	self->MaxLED = Chroma.Keyboard_MaxLED();
	return 0;
}


static PyTypeObject Keypad_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Keypad",             /* tp_name */
	sizeof(ChromaKeypad),             /* tp_basicsize */
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
	docKeypad,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	KeypadMethods,             /* tp_methods */
	keypadmembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(Keypad_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

