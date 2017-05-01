#include "Header\Mousepad.h"

PyObject* set_mousepad(PyObject* self, PyObject* args)
{

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "O", &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setColor(color) | setColor((R, G, B))");
		return nullptr;
	}


	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	return Chroma.setMousepad(color);
}

PyObject* set_mousepadbyled(PyObject* self, PyObject* args)
{
	long x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyLED(led, color) | setbyLED(led, (R, G, B))");
		return nullptr;
	}

	if (x > ChromaSDK::Mousepad::MAX_LEDS || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! LED out of range");
		return nullptr;
	}

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}


	return Chroma.setMousepadbyLED(x, color);

}

PyObject* clear_mousepad(PyObject* self, PyObject* args)
{

	return Chroma.clearMousepadEffect();


}

PyObject* applyEffectMousepad(PyObject* self, PyObject* args)
{

	return Chroma.applyMousepadEffect();

}

PyObject* ResetEffectMousepad(PyObject* self, PyObject* args) {

	Chroma.ResetEffects(MOUSEMAT_DEVICES);

	return PyUnicode_FromString("Success");

}

PyObject*WaveEffectMousepad(PyObject* self, PyObject* args) {


	int direction;
	if (!PyArg_ParseTuple(args, "l", &direction))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setWave(direction) | setWave(direction)");
		return nullptr;
	}

	if (direction < 0 || direction > 2) {
		PyErr_SetString(SyntaxError, "Invalid Arguments! Duration needs to be 1(left to right)-2(right to left)");
		return nullptr;
	}

	return Chroma.setMousepadWave(direction);
}

PyObject* BreathingEffectMousepad(PyObject* self, PyObject* args) {


	int temp;
	bool mode;
	PyObject* first;
	PyObject* second;
	if (!PyArg_ParseTuple(args, "IOO", &temp, &first, &second))
	{
		return nullptr;
	}
	COLORREF FIRST = NULL;
	COLORREF SECOND = NULL;
	if (temp == 0)
	{
		mode = false;
	}
	else if (temp == 1)
	{
		mode = true;
	}
	else
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Mode needs to be 0(false)-1(RZRESULT_SUCCESS)");
		return nullptr;
	}


	if (mode == true) {

		if (!Chroma.Colortest(first, FIRST))
		{
			PyErr_SetString(SyntaxError, "Invalid Arguments! First color needs to be (0-255, 0-255, 0-255)");
			return nullptr;
		}
		if (!Chroma.Colortest(second, SECOND))
		{
			PyErr_SetString(SyntaxError, "Invalid Arguments! First color needs to be (0-255, 0-255, 0-255)");
			return nullptr;
		}

	}

	return Chroma.setMousepadBreathing(mode, FIRST, SECOND);
}
