#include "Headset.h"



PyObject* set_headset(PyObject* self, PyObject* args){

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "O", &Color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setColor(color) | setColor((R, G, B))");
		return nullptr;
	}

	COLORREF color;

	if (!Chroma.Colortest(Color, color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	Chroma.setHeadset(color);

	return PyUnicode_FromString("Success");
}

PyObject* set_headsetbyled(PyObject* self, PyObject* args){
	size_t x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyLED(led, color) | setbyLED(led, (R, G, B))");
		return nullptr;
	}

	COLORREF color;

	if (!Chroma.Colortest(Color, color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	Chroma.setHeadsetbyLED(x, color);

	return PyUnicode_FromString("Success");
}

PyObject* clear_headset(PyObject* self, PyObject* args){
	
	Chroma.clearHeadsetEffect();

	return PyUnicode_FromString("Success");
}

PyObject* applyEffectHeadset(PyObject* self, PyObject* args){

	Chroma.applyHeadsetEffect();

	return PyUnicode_FromString("Success");

}

PyObject* ResetEffectHeadset(PyObject* self, PyObject* args) {

	Chroma.ResetEffects(HEADSET_DEVICES);

	return PyUnicode_FromString("Success");

}

PyObject* BreathingEffectHeadset(PyObject* self, PyObject* args) {

	PyObject* first;

	if (!PyArg_ParseTuple(args, "O", &first)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setBreathing(color) | setBreathing( (R, G, B))");
		return nullptr;
	}

	COLORREF FIRST = NULL;


	if (!Chroma.Colortest(first, FIRST)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	Chroma.setHeadsetBreathing(FIRST);

	return PyUnicode_FromString("Success");
}

int Headset_init(ChromaHeadset *self, PyObject *args, PyObject *kwds){
	
	self->MaxLED = Chroma.Headset_MaxLED();
	return 0;
}