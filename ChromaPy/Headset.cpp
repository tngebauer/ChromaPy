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

	Chroma.setHeadset(color);

	return PyUnicode_FromString("Success");
}

PyObject* set_headsetbyled(PyObject* self, PyObject* args){
	size_t x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyLED(LED, color) | setbyLED(LED, (R, G, B))");
		return nullptr;
	}

	if (x > ChromaSDK::Headset::MAX_LEDS || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! LED out of range");
		return nullptr;
	}

	COLORREF color;

	if (!Chroma.Colortest(Color, color)){
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setHeadsetbyLED(x, color);
	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: "+result);
		return nullptr;
	}

}

PyObject* clear_headset(PyObject* self, PyObject* args){
	
	RZRESULT result = Chroma.clearHeadsetEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* applyEffectHeadset(PyObject* self, PyObject* args){

	RZRESULT result = Chroma.applyHeadsetEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
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

	RZRESULT result = Chroma.setHeadsetBreathing(FIRST);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

int Headset_init(ChromaHeadset *self, PyObject *args, PyObject *kwds){
	
	self->MaxLED = Chroma.Headset_MaxLED();
	return 0;
}