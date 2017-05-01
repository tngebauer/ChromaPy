#pragma once
#include "ChromaSDK.h"



typedef struct
{
	PyObject_HEAD
	long MaxRow;
	long MaxColumn;
	long MaxLED;


} ChromaKeyboard;

static PyMemberDef keyboardmembers[] = {

	{ "MaxRow", T_INT, offsetof(ChromaKeyboard, MaxRow), READONLY, docKeyboardMaxRow },
	{ "MaxColumn", T_INT, offsetof(ChromaKeyboard, MaxColumn), READONLY, docKeyboardMaxColumn },
	{ "MaxLED", T_INT, offsetof(ChromaKeyboard, MaxLED), READONLY, docKeyboardMaxLED },
	{nullptr }  /* Sentinel */
};

PyObject* set_keyboard(PyObject* self, PyObject* args);

PyObject* set_keyboardbycord(PyObject* self, PyObject* args);

PyObject* set_keyboardbyrow(PyObject* self, PyObject* args);

PyObject* set_keyboardbycol(PyObject* self, PyObject* args);

PyObject* clear_keyboard(PyObject* self, PyObject* args);

PyObject* applyEffectKeyboard(PyObject* self, PyObject* args);

PyObject* ResetEffectKeyboard(PyObject* self, PyObject* args);

PyObject* ReactiveEffectKeyboard(PyObject* self, PyObject* args);

PyObject* WaveEffectKeyboard(PyObject* self, PyObject* args);

PyObject* BreathingEffectKeyboard(PyObject* self, PyObject* args);




static PyMethodDef KeyboardMethods[] = {
	{ "setColor", static_cast<PyCFunction>(set_keyboard), METH_VARARGS, docKeyboardsetColor },
	{ "setbyGrid", static_cast<PyCFunction>(set_keyboardbycord), METH_VARARGS, docKeyboardsetbyCord },
	{ "setbyRow", reinterpret_cast<PyCFunction>(set_keyboardbyrow), METH_VARARGS, docKeyboardsetbyRow },
	{ "setbyCol", reinterpret_cast<PyCFunction>(set_keyboardbycol), METH_VARARGS, docKeyboardsetbyCol },
	{ "setReactive", static_cast<PyCFunction>(ReactiveEffectKeyboard),METH_VARARGS , docKeyboardsetReactive },
	{ "setBreathing", static_cast<PyCFunction>(BreathingEffectKeyboard),METH_VARARGS , docKeyboardsetBreathing },
	{ "setWave", static_cast<PyCFunction>(WaveEffectKeyboard),METH_VARARGS , docKeyboardsetWave },
	{ "clearGrid", reinterpret_cast<PyCFunction>(clear_keyboard), METH_NOARGS, docKeyboardclearEffect},
	{ "applyGrid", static_cast<PyCFunction>(applyEffectKeyboard), METH_NOARGS, docKeyboardapply},
	{ "resetEffect", static_cast<PyCFunction>(ResetEffectKeyboard), METH_NOARGS, docKeyboardresetEffect },

	
	{ nullptr,nullptr,0,nullptr }



};

static int Keyboard_init(ChromaKeyboard *self, PyObject *args, PyObject *kwds)
{

	self->MaxRow = Chroma.Keyboard_MaxRow();
	self->MaxColumn = Chroma.Keyboard_MaxCol();
	self->MaxLED = Chroma.Keyboard_MaxLED();
	return 0;
}


static PyTypeObject Keyboard_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"Keyboard",             /* tp_name */
	sizeof(ChromaKeyboard),             /* tp_basicsize */
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
	docKeyboard,           /* tp_doc */
	nullptr,                         /* tp_traverse */
	nullptr,                         /* tp_clear */
	nullptr,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	nullptr,                         /* tp_iter */
	nullptr,                         /* tp_iternext */
	KeyboardMethods,             /* tp_methods */
	keyboardmembers,             /* tp_members */
	nullptr,                         /* tp_getset */
	nullptr,                         /* tp_base */
	nullptr,                         /* tp_dict */
	nullptr,                         /* tp_descr_get */
	nullptr,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	reinterpret_cast<initproc>(Keyboard_init),      /* tp_init */
	nullptr,                         /* tp_alloc */
	nullptr,                 /* tp_new */
};

