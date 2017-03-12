#include "Header\Keyboard.h"


PyObject* set_keyboard(PyObject* self, PyObject* args)
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
	RZRESULT result = Chroma.setKeyboard(color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}


PyObject* set_keyboardbycord(PyObject* self, PyObject* args)
{
	size_t x, y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "llO", &x, &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyGrid(x, y, color) | setbyGrid(x, y, (R, G, B))");
		return nullptr;
	}

	if (x > ChromaSDK::Keyboard::MAX_COLUMN || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! X-coordinate out of range");
		return nullptr;
	}
	else if (y > ChromaSDK::Keyboard::MAX_ROW || y < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! Y-coordinate out of range");
		return nullptr;
	}

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeyboardbyCord(x, y, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* set_keyboardbyrow(PyObject* self, PyObject* args)
{
	size_t y;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &y, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyRow(row, color) | setbyGrid(row, (R, G, B))");
		return nullptr;
	}

	 if (y > ChromaSDK::Keyboard::MAX_ROW || y < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! Y-coordinate out of range");
		return nullptr;
	}

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeyboardbyRow(y, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* set_keyboardbycol(PyObject* self, PyObject* args)
{
	size_t x;

	PyObject *Color;
	if (!PyArg_ParseTuple(args, "lO", &x, &Color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Usage: setbyCol(column, color) | setbyGrid(column, (R, G, B))");
		return nullptr;
	}

	if (x > ChromaSDK::Keyboard::MAX_COLUMN || x < 0) {
		PyErr_SetString(SyntaxError, "Invalid Argument! X-coordinate out of range");
		return nullptr;
	}
	

	COLORREF color;
	if (!Chroma.Colortest(Color, color))
	{
		PyErr_SetString(SyntaxError, "Invalid Arguments! Color needs to be (0-255, 0-255, 0-255)");
		return nullptr;
	}

	RZRESULT result = Chroma.setKeyboardbyCol(x, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* clear_keyboard(PyObject* self, PyObject* args)
{
	RZRESULT result = Chroma.clearKeyboardEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* applyEffectKeyboard(PyObject* self, PyObject* args)
{
	RZRESULT result = Chroma.applyKeyboardEffect();

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* ResetEffectKeyboard(PyObject* self, PyObject* args) {

	Chroma.ResetEffects(KEYBOARD_DEVICES);

	return PyUnicode_FromString("Success");

}

PyObject* ReactiveEffectKeyboard(PyObject* self, PyObject* args) {

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
	
	RZRESULT result = Chroma.setKeyboardReactive(duration, color);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* WaveEffectKeyboard(PyObject* self, PyObject* args) {


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
	RZRESULT result = Chroma.setKeyboardWave(direction);

	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

PyObject* BreathingEffectKeyboard(PyObject* self, PyObject* args) {


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
		PyErr_SetString(SyntaxError, "Invalid Arguments! mode needs to be 0(false)-1(true)");
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

	RZRESULT result = Chroma.setKeyboardBreathing(mode, FIRST, SECOND);


	if (result == TRUE) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}

