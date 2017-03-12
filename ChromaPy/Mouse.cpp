#include "Header\Mouse.h"

PyObject* set_mouse(PyObject* self, PyObject* args)
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
	Chroma.setMouse(color);



	return PyUnicode_FromString("Success");
}

PyObject* set_mousebycord(PyObject* self, PyObject* args)
{
	size_t x;
	size_t y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "llO", &x, &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyGrid(x, y, color) | setColor(x, y, (R, G, B))");
		return nullptr;
	}


	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}


	Chroma.setMousebyCord(x, y, color);


	return PyUnicode_FromString("Success");
}

PyObject* set_mousebyrow(PyObject* self, PyObject* args)
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


	Chroma.setMousebyRow(y, color);


	return PyUnicode_FromString("Success");
}

PyObject* set_mousebycol(PyObject* self, PyObject* args)
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


	Chroma.setMousebyCol(x, color);


	return PyUnicode_FromString("Success");
}

PyObject* clear_mouse(PyObject* self, PyObject* args)
{

	Chroma.clearMouseEffect();

	return PyUnicode_FromString("Success");

}

PyObject* applyEffectMouse(PyObject* self, PyObject* args)
{

	Chroma.applyMouseEffect();

	return PyUnicode_FromString("Success");

}

PyObject* ResetEffectMouse(PyObject* self, PyObject* args) {

	Chroma.ResetEffects(MOUSE_DEVICES);

	return PyUnicode_FromString("Success");

}

PyObject*WaveEffectMouse(PyObject* self, PyObject* args) {


	int direction;
	if (!PyArg_ParseTuple(args, "l", &direction))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setWave(direction) | setWave(direction)");
		return nullptr;
	}

	if (direction < 0 || direction > 2) {
		PyErr_SetString(SyntaxError, "Invalid Arguments! Duration needs to be 1(top to bottom)-2(bottom to top)");
		return nullptr;
	}
	Chroma.setMouseWave(direction);

	return PyUnicode_FromString("Success");
}

PyObject* BreathingEffectMouse(PyObject* self, PyObject* args) {


	int temp;
	bool mode;
	PyObject* first;
	PyObject* second;
	if (!PyArg_ParseTuple(args, "IOO", &temp, &first, &second))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setBreathing(mode, first color, second color)");
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
		PyErr_SetString(SyntaxError, "Invalid Arguments! Mode needs to be 0(false)-1(true)");
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
			PyErr_SetString(SyntaxError, "Invalid Arguments! Second color needs to be (0-255, 0-255, 0-255)");
			return nullptr;
		}
	}

	Chroma.setMouseBreathing(mode, FIRST, SECOND);

	return PyUnicode_FromString("Success");
}