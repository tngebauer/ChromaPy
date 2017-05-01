#include "Header\Headset.h"



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

	return Chroma.setHeadset(color);

}

PyObject* set_headsetbyled(PyObject* self, PyObject* args){
	long x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyLED(LED, color) | setbyLED(LED, (R, G, B))");
		return nullptr;
	}

	if ((x > ChromaSDK::Headset::MAX_LEDS) || (x < 0)) {
		PyErr_SetString(SyntaxError, "Invalid Argument! LED out of range");
		return nullptr;
	}

	COLORREF color;

	if (!Chroma.Colortest(Color, color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	return Chroma.setHeadsetbyLED(x, color);

}

PyObject* clear_headset(PyObject* self, PyObject* args){
	
	return Chroma.clearHeadsetEffect();
}

PyObject* applyEffectHeadset(PyObject* self, PyObject* args){

	return Chroma.applyHeadsetEffect();
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

	return Chroma.setHeadsetBreathing(FIRST);

}

int Headset_init(ChromaHeadset *self, PyObject *args, PyObject *kwds){
	
	self->MaxLED = Chroma.Headset_MaxLED();
	return 0;
}