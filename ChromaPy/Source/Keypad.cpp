#include "Keypad.h"


PyObject* set_keypad(PyObject* self, PyObject* args)
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
	Chroma.setKeypad(color);



	return PyUnicode_FromString("Success");
}

PyObject* set_keypadbycord(PyObject* self, PyObject* args)
{
	size_t x;
	size_t y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "llO", &x, &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyGrid(x, y, color) | setbyGrid(x, y, (R, G, B))");
		return nullptr;
	}


	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}


	Chroma.setKeypadbyCord(x, y, color);


	return PyUnicode_FromString("Success");
}

PyObject* set_keypadbyrow(PyObject* self, PyObject* args)
{

	size_t y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyRow(row, color) | setbyRow(row, (R, G, B))");
		return nullptr;
	}


	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}


	Chroma.setKeypadbyRow(y, color);


	return PyUnicode_FromString("Success");
}


PyObject* set_keypadbycol(PyObject* self, PyObject* args)
{

	size_t x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyCol(column, color) | setbyCol(column, (R, G, B))");
		return nullptr;
	}


	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}


	Chroma.setKeypadbyCol(x, color);


	return PyUnicode_FromString("Success");


}

PyObject* clear_keypad(PyObject* self, PyObject* args)
{

	Chroma.clearKeypadEffect();

	return PyUnicode_FromString("Success");

}

PyObject* applyEffectKeypad(PyObject* self, PyObject* args)
{

	Chroma.applyKeypadEffect();

	return PyUnicode_FromString("Success");

}

PyObject* ResetEffectKeypad(PyObject* self, PyObject* args) {

	Chroma.ResetEffects(KEYPAD_DEVICES);

	return PyUnicode_FromString("Success");

}

PyObject*ReactiveEffectKeypad(PyObject* self, PyObject* args) {

	PyObject *Color;
	int duration;
	if (!PyArg_ParseTuple(args, "lO", &duration, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setReactive(duration, color) | setbyGrid(duration, (R, G, B))");
		return nullptr;
	}
	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}
	if (duration < 0 || duration > 3) {
		PyErr_SetString(SyntaxError, "Invalid Arguments! Duration needs to be 0(short)-3(long)");
		return nullptr;
	}
	Chroma.setKeypadReactive(duration, color);

	return PyUnicode_FromString("Success");
}

PyObject*WaveEffectKeypad(PyObject* self, PyObject* args) {


	int direction;
	if (!PyArg_ParseTuple(args, "l", &direction))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setWave(direction) | setWave(direction)");
		return nullptr;
	}

	if (direction < 0 || direction > 2) {
		PyErr_SetString(SyntaxError, "Invalid Arguments! Duration needs to be 0(left to right)-1(right to left)");
		return nullptr;
	}
	Chroma.setKeypadWave(direction);

	return PyUnicode_FromString("Success");
}

PyObject* BreathingEffectKeypad(PyObject* self, PyObject* args) {


	int mode;
	bool it;
	PyObject* first;
	PyObject* second;
	if (!PyArg_ParseTuple(args, "IOO", &mode, &first, &second))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setBreathing(mode, first color, second color)");
		return nullptr;
	}
	COLORREF FIRST = NULL;
	COLORREF SECOND = NULL;

	if (mode == 0){ it = false; }
	else if (mode == 1)
	{
		it = true;
	}
	else
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Mode needs to be 0(false)-1(true)");
		return nullptr;
	}

	if (it == true) {

		if (!Chroma.Colortest(first, FIRST))
		{
			PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
			return nullptr;

		}
		if (!Chroma.Colortest(second, SECOND))
		{
			PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
			return nullptr;
		}


	}

	Chroma.setKeypadBreathing(it, FIRST, SECOND);


	return PyUnicode_FromString("Success");
}