#include "Header\Smart Home.h"

PyObject* set_color(SmartHome *self, PyObject *args) {

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "O", &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyRow(row, color) | setbyGrid(row, (R, G, B)");
		return nullptr;
	}
	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	if(self->Bulb.color(color)) { return PyUnicode_FromString("Successful"); }
	else { return PyUnicode_FromString("Error"); }

}

PyObject* set_ip(SmartHome *self, PyObject *args) {
	char* IP;
	if (!PyArg_ParseTuple(args, "s", &IP))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setIP(IP)");
		return nullptr;
	}

	self->Bulb.changeip(IP);
	return PyUnicode_FromString("Successful");

}

PyObject* power(SmartHome *self, PyObject *args) {
	char* IP;
	if (!PyArg_ParseTuple(args, "s", &IP))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setPower(\"on\") | setPower(\"on\")");
		return nullptr;
	}

	if(self->Bulb.power(IP)) { return PyUnicode_FromString("Successful"); }
	else { return PyUnicode_FromString("Error"); }

}

PyObject* brightness(SmartHome *self, PyObject *args) {
	int percentage;
	if (!PyArg_ParseTuple(args, "i", &percentage))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setBrightness(10-100)");
		return nullptr;
	}
	if (percentage < 0 || percentage > 100) {
		PyErr_SetString(SyntaxError, "Invalid Arguments! Brightness needs to be between 10-100");
		return nullptr;
	}

	if (self->Bulb.brightness(percentage)) { return PyUnicode_FromString("Successful"); }
	else { return PyUnicode_FromString("Error"); }

}

PyObject* getbrightness(SmartHome *self, PyObject *args) {

	return PyLong_FromSize_t(self->Bulb.getBrightness());

}

PyObject* getrgb(SmartHome *self, PyObject *args) {

	return PyLong_FromSize_t(self->Bulb.getRGB());

}

PyObject* getpower(SmartHome *self, PyObject *args) {

	return PyBool_FromLong(self->Bulb.getPowerState());

}