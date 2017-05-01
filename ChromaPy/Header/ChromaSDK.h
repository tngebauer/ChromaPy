#pragma once
#ifndef _CHROMASDKIMPL_H_
#define _CHROMASDKIMPL_H_

#ifndef DLL_COMPILED
#define DLL_INTERNAL __declspec( dllexport )
#endif 
#ifdef _WIN64
#define CHROMASDKDLL        _T("RzChromaSDK64.dll")
#else
#define CHROMASDKDLL        _T("RzChromaSDK.dll")
#endif
#include "include.h"

// Define all Colours you want
const COLORREF BLACK = RGB(0, 0, 0);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF YELLOW = RGB(255, 255, 0);
const COLORREF PURPLE = RGB(128, 0, 128);
const COLORREF CYAN = RGB(00, 255, 255);
const COLORREF ORANGE = RGB(255, 165, 00);
const COLORREF PINK = RGB(255, 192, 203);
const COLORREF GREY = RGB(125, 125, 125);

#define ALL_DEVICES         0
#define KEYBOARD_DEVICES    1
#define MOUSEMAT_DEVICES    2
#define MOUSE_DEVICES       3
#define HEADSET_DEVICES     4
#define KEYPAD_DEVICES      5
extern PyObject *SyntaxError;

class Chroma_Implementation
{
private:
	HMODULE ChromaModule;

	ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Keyboard_Effect = {};
	ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 Mouse_Effect = {};
	ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Mousepad_Effect = {};
	ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Keypad_Effect = {};
	ChromaSDK::Headset::CUSTOM_EFFECT_TYPE Headset_Effect = {};

	static RZRESULT IsDeviceConnected(RZDEVICEID DeviceId);

public:
	Chroma_Implementation();
	~Chroma_Implementation();
	RZRESULT Initialize();

	//Static Effect
	static void ResetEffects(UINT DeviceType);
	PyObject* set_all(COLORREF Color);
	PyObject* setKeyboard(COLORREF Color);
	PyObject* setMouse(COLORREF Color);
	PyObject* setMousepad(COLORREF Color);
	PyObject* setKeypad(COLORREF Color);
	PyObject* setHeadset(COLORREF Color);

	PyObject* setKeyboardbyCord(long x, long y, COLORREF Color);
	PyObject* setMousebyCord(long x, long y, COLORREF Color);
	PyObject* setMousepadbyLED(long led, COLORREF Color);
	PyObject* setKeypadbyCord(long x, long y, COLORREF Color);
	PyObject* setHeadsetbyLED(long led, COLORREF Color);

	PyObject* setKeyboardbyRow(long Row, COLORREF Color);
	PyObject* setKeyboardbyCol(long Col, COLORREF Color);

	PyObject* setMousebyRow(long Row, COLORREF Color);
	PyObject* setMousebyCol(long Col, COLORREF Color);

	PyObject* setKeypadbyRow(long Row, COLORREF Color);
	PyObject* setKeypadbyCol(long Col, COLORREF Color);

	//Reactive Effect
	static PyObject* setKeyboardReactive(long Duration, COLORREF Color);
	static PyObject* setKeypadReactive(long Duration, COLORREF Color);

	//Wave Effect
	static PyObject* setKeyboardWave(long direction);
	static PyObject* setKeypadWave(long direction);
	static PyObject* setMouseWave(long direction);
	static PyObject* setMousepadWave(long direction);

	//Breathing Effect
	static PyObject* setKeyboardBreathing(bool mode, COLORREF first, COLORREF second);
	static PyObject* setKeypadBreathing(bool mode, COLORREF first, COLORREF second);
	static PyObject* setMouseBreathing(bool mode, COLORREF first, COLORREF second);
	static PyObject* setMousepadBreathing(bool mode, COLORREF first, COLORREF second);
	static PyObject* setHeadsetBreathing(COLORREF first);

	//clear Grid
	PyObject* clearKeyboardEffect();
	PyObject* clearMouseEffect();
	PyObject* clearKeypadEffect();
	PyObject* clearMousepadEffect();
	PyObject* clearHeadsetEffect();

	//apply Effect
	PyObject* applyMouseEffect();
	PyObject* applyMousepadEffect();
	PyObject* applyKeyboardEffect();
	PyObject* applyKeypadEffect();
	PyObject* applyHeadsetEffect();

	//Constants
	static long Keyboard_MaxCol();
	static long Keyboard_MaxRow();
	static long Keyboard_MaxLED();
	static long Mouse_MaxRow();
	static long Mouse_MaxCol();
	static long Mouse_MaxLED();
	static long Mousepad_MaxLED();
	static long Keypad_MaxRow();
	static long Keypad_MaxCol();
	static long Keypad_MaxLED();
	static long Headset_MaxLED();

	static bool Colortest(PyObject *Color, COLORREF &color);
	static PyObject* CheckError(RZRESULT result);
	static void ConnectedDevices(vector<char*> &devices);

	vector<Yeelight> Lights;

};
extern Chroma_Implementation Chroma;






#endif
