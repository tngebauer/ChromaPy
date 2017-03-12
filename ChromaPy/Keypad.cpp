#include "Header\Keypad.h"


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
	RZRESULT result = Chroma.setKeypad(color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* set_keypadbycord(PyObject* self, PyObject* args)
{
	size_t x, y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "llO", &x, &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyGrid(x, y, color) | setbyGrid(x, y, (R, G, B))");
		return nullptr;
	}

	if (x > ChromaSDK::Keypad::MAX_COLUMN || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! X-coordinate out of range");
		return nullptr;
	}
	else if (y > ChromaSDK::Keypad::MAX_ROW || y < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! Y-coordinate out of range");
		return nullptr;
	}

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeypadbyCord(x, y, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
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

	if (y > ChromaSDK::Keypad::MAX_ROW || y < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! Y-coordinate out of range");
		return nullptr;
	}
	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeypadbyRow(y, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
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

	if (x > ChromaSDK::Keypad::MAX_COLUMN || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! X-coordinate out of range");
		return nullptr;
	}

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeypadbyCol(x, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* clear_keypad(PyObject* self, PyObject* args)
{
	RZRESULT result = Chroma.clearKeypadEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* applyEffectKeypad(PyObject* self, PyObject* args)
{
	RZRESULT result = Chroma.applyKeypadEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
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
	RZRESULT result = Chroma.setKeypadReactive(duration, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
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
	RZRESULT result = Chroma.setKeypadWave(direction);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* BreathingEffectKeypad(PyObject* self, PyObject* args) {

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

	if (temp == 0){ mode = false; }
	else if (temp == 1) { mode = true; }
	else
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Mode needs to be 0(false)-1(true)");
		return nullptr;
	}

	if (mode == true) {

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

	RZRESULT result = Chroma.setKeypadBreathing(mode, FIRST, SECOND);


	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}