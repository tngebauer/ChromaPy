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

class Chroma_Implementation
{
public:
	ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Keyboard_Effect = {};
	ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 Mouse_Effect = {};
	ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Mousepad_Effect = {};
	ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Keypad_Effect = {};
	ChromaSDK::Headset::CUSTOM_EFFECT_TYPE Headset_Effect = {};

	Chroma_Implementation();
	~Chroma_Implementation();
	BOOL Initialize();
	//Static Effect
	static void ResetEffects(UINT DeviceType);
	BOOL set_all(COLORREF Color);
	BOOL setKeyboard(COLORREF Color);
	BOOL setMouse(COLORREF Color);
	BOOL setMousepad(COLORREF Color);
	BOOL setKeypad(COLORREF Color);
	BOOL setHeadset(COLORREF Color);

	BOOL setKeyboardbyCord(size_t x, size_t y, COLORREF Color);
	BOOL setMousebyCord(size_t x, size_t y, COLORREF Color);
	BOOL setMousepadbyLED(size_t led, COLORREF Color);
	BOOL setKeypadbyCord(size_t x, size_t y, COLORREF Color);
	BOOL setHeadsetbyLED(size_t led, COLORREF Color);

	BOOL setKeyboardbyRow(size_t Row, COLORREF Color);
	BOOL setKeyboardbyCol(size_t Col, COLORREF Color);

	BOOL setMousebyRow(size_t Row, COLORREF Color);
	BOOL setMousebyCol(size_t Col, COLORREF Color);

	BOOL setKeypadbyRow(size_t Row, COLORREF Color);
	BOOL setKeypadbyCol(size_t Col, COLORREF Color);

	//Reactive Effect
	static BOOL setKeyboardReactive(size_t Duration, COLORREF Color);
	static BOOL setKeypadReactive(size_t Duration, COLORREF Color);
	//Wave Effect
	static BOOL setKeyboardWave(size_t direction);
	static BOOL setKeypadWave(size_t direction);
	static BOOL setMouseWave(size_t direction);
	static BOOL setMousepadWave(size_t direction);
	//Breathing Effect
	static BOOL setKeyboardBreathing(bool mode, COLORREF first, COLORREF second);
	static BOOL setKeypadBreathing(bool mode, COLORREF first, COLORREF second);
	static BOOL setMouseBreathing(bool mode, COLORREF first, COLORREF second);
	static BOOL setMousepadBreathing(bool mode, COLORREF first, COLORREF second);
	static BOOL setHeadsetBreathing(COLORREF first);




	//clear Grid
	BOOL clearKeyboardEffect();
	BOOL clearMouseEffect();
	BOOL clearKeypadEffect();
	BOOL clearMousepadEffect();
	BOOL clearHeadsetEffect();

	//apply Effect
	BOOL applyMouseEffect();
	BOOL applyMousepadEffect();
	BOOL applyKeyboardEffect();
	BOOL applyKeypadEffect();
	BOOL applyHeadsetEffect();

	//Constants
	static size_t Keyboard_MaxCol();
	static size_t Keyboard_MaxRow();
	static size_t Keyboard_MaxLED();
	static size_t Mouse_MaxRow();
	static size_t Mouse_MaxCol();
	static size_t Mouse_MaxLED();
	static size_t Mousepad_MaxLED();
	static size_t Keypad_MaxRow();
	static size_t Keypad_MaxCol();
	static size_t Keypad_MaxLED();
	static size_t Headset_MaxLED();

	static bool Colortest(PyObject *Color, COLORREF &color);

	static bool IsDeviceConnected(RZDEVICEID DeviceId);
	static void ConnectedDevices(std::vector<char*> &devices);

private:
	HMODULE m_ChromaSDKModule;

};


extern Chroma_Implementation Chroma;
static PyObject *SyntaxError;
#endif
