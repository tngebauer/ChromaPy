#include "ChromaSDK.h"


typedef RZRESULT(*INIT)();
typedef RZRESULT(*UNINIT)();
typedef RZRESULT(*CREATEEFFECT)(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEKEYBOARDEFFECT)(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEHEADSETEFFECT)(ChromaSDK::Headset::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEMOUSEPADEFFECT)(ChromaSDK::Mousepad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEMOUSEEFFECT)(ChromaSDK::Mouse::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEKEYPADEFFECT)(ChromaSDK::Keypad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*SETEFFECT)(RZEFFECTID EffectId);
typedef RZRESULT(*DELETEEFFECT)(RZEFFECTID EffectId);
typedef RZRESULT(*REGISTEREVENTNOTIFICATION)(HWND hWnd);
typedef RZRESULT(*UNREGISTEREVENTNOTIFICATION)();
typedef RZRESULT(*QUERYDEVICE)(RZDEVICEID DeviceId, ChromaSDK::DEVICE_INFO_TYPE &DeviceInfo);

INIT Init = nullptr;
UNINIT UnInit = nullptr;
CREATEEFFECT CreateEffect = nullptr;
CREATEKEYBOARDEFFECT CreateKeyboardEffect = nullptr;
CREATEMOUSEEFFECT CreateMouseEffect = nullptr;
CREATEHEADSETEFFECT CreateHeadsetEffect = nullptr;
CREATEMOUSEPADEFFECT CreateMousepadEffect = nullptr;
CREATEKEYPADEFFECT CreateKeypadEffect = nullptr;
SETEFFECT SetEffect = nullptr;
DELETEEFFECT DeleteEffect = nullptr;
QUERYDEVICE QueryDevice = nullptr;



BOOL Chroma_Implementation::IsDeviceConnected(RZDEVICEID DeviceId)
{
	if (QueryDevice != nullptr)
	{
		ChromaSDK::DEVICE_INFO_TYPE DeviceInfo = {};
		RZRESULT Result = QueryDevice(DeviceId, DeviceInfo);

		return DeviceInfo.Connected;
	}

	return FALSE;
}


Chroma_Implementation::Chroma_Implementation() :m_ChromaSDKModule(nullptr)
{

}
Chroma_Implementation::~Chroma_Implementation()
{
}

BOOL Chroma_Implementation::Initialize()
{
	if (m_ChromaSDKModule == nullptr)
	{
		m_ChromaSDKModule = LoadLibrary(CHROMASDKDLL);
		if (m_ChromaSDKModule == nullptr)
		{
			return FALSE;
		}
	}

	if (Init == nullptr)
	{
		RZRESULT Result = RZRESULT_INVALID;
		Init = reinterpret_cast<INIT>(GetProcAddress(m_ChromaSDKModule, "Init"));
		if (Init)
		{
			Result = Init();
			if (Result == RZRESULT_SUCCESS)
			{
				CreateEffect = reinterpret_cast<CREATEEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateEffect"));
				CreateKeyboardEffect = reinterpret_cast<CREATEKEYBOARDEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateKeyboardEffect"));
				CreateMouseEffect = reinterpret_cast<CREATEMOUSEEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateMouseEffect"));
				CreateHeadsetEffect = reinterpret_cast<CREATEHEADSETEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateHeadsetEffect"));
				CreateMousepadEffect = reinterpret_cast<CREATEMOUSEPADEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateMousepadEffect"));
				CreateKeypadEffect = reinterpret_cast<CREATEKEYPADEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateKeypadEffect"));
				SetEffect = reinterpret_cast<SETEFFECT>(GetProcAddress(m_ChromaSDKModule, "SetEffect"));
				DeleteEffect = reinterpret_cast<DELETEEFFECT>(GetProcAddress(m_ChromaSDKModule, "DeleteEffect"));
				QueryDevice = reinterpret_cast<QUERYDEVICE>(GetProcAddress(m_ChromaSDKModule, "QueryDevice"));

				if (CreateEffect &&
					CreateKeyboardEffect &&
					CreateMouseEffect &&
					CreateHeadsetEffect &&
					CreateMousepadEffect &&
					CreateKeypadEffect &&
					SetEffect &&
					DeleteEffect &&
					QueryDevice)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
	}

	return TRUE;
}
void Chroma_Implementation::ResetEffects(UINT DeviceType)
{
	switch (DeviceType)
	{
	case 0:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateMousepadEffect)
		{
			CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateMouseEffect)
		{
			CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 1:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 2:
		if (CreateMousepadEffect)
		{
			CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 3:
		if (CreateMouseEffect)
		{
			CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	default: ;
	}
}
//set static effect to all/specific devices
BOOL Chroma_Implementation::set_all(COLORREF Color)
{
	this->setKeyboard(Color);
	this->setMouse(Color);
	this->setMousepad(Color);

	return true;
}
BOOL Chroma_Implementation::setKeyboard(COLORREF Color)
{


	for (UINT row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++) {
			this->Keyboard_Effect.Color[row][col] = Color;
		}
	}




	return TRUE;
}
BOOL Chroma_Implementation::setMousepad(COLORREF Color)
{





	for (UINT count = 0; count < ChromaSDK::Mousepad::MAX_LEDS; count++) {
		this->Mousepad_Effect.Color[count] = Color;
	}

	return TRUE;
}
BOOL Chroma_Implementation::setMouse(COLORREF Color)
{







	for (UINT row = 0; row < ChromaSDK::Mouse::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Mouse::MAX_COLUMN; col++) {
			this->Mouse_Effect.Color[row][col] = Color;
		}
	}

	return TRUE;
}
BOOL Chroma_Implementation::setKeypad(COLORREF Color) {
	for (UINT row = 0; row < ChromaSDK::Keypad::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Keypad::MAX_COLUMN; col++) {
			this->Keypad_Effect.Color[row][col] = Color;
		}
	}

	return TRUE;
}
BOOL Chroma_Implementation::setHeadset(COLORREF Color) {
	for (UINT count = 0; count < ChromaSDK::Headset::MAX_LEDS; count++) {
		this->Headset_Effect.Color[count] = Color;
	}

	return TRUE;
}

//Set Keyboard by x- and y-cords
BOOL Chroma_Implementation::setKeyboardbyCord(size_t x, size_t y, COLORREF Color)
{
	if (y < ChromaSDK::Keyboard::MAX_ROW && x < ChromaSDK::Keyboard::MAX_COLUMN)
	{


		this->Keyboard_Effect.Color[y][x] = Color;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
//Set Mouse by x- and y-cords
BOOL Chroma_Implementation::setMousebyCord(size_t x, size_t y, COLORREF Color)
{
	if (y < ChromaSDK::Mouse::MAX_ROW && x < ChromaSDK::Mouse::MAX_COLUMN)
	{

		this->Mouse_Effect.Color[y][x] = Color;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
//set Mousepad by LEDs
BOOL Chroma_Implementation::setMousepadbyLED(size_t led, COLORREF Color)
{
	if (led < ChromaSDK::Mousepad::MAX_LEDS)
	{

		this->Mousepad_Effect.Color[led] = Color;
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

BOOL Chroma_Implementation::setKeypadbyCord(size_t x, size_t y, COLORREF Color) {

	if (y < ChromaSDK::Keypad::MAX_ROW && x < ChromaSDK::Keypad::MAX_COLUMN)
	{


		this->Keypad_Effect.Color[y][x] = Color;
		return TRUE;
	}
	else
	{
		return FALSE;
	}


}

BOOL Chroma_Implementation::setHeadsetbyLED(size_t led, COLORREF Color) {

	if (led < ChromaSDK::Headset::MAX_LEDS) {

		this->Headset_Effect.Color[led] = Color;
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//Apply effects
BOOL Chroma_Implementation::applyMouseEffect()
{
	return CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &this->Mouse_Effect, nullptr);
}
BOOL Chroma_Implementation::applyMousepadEffect()
{
	return CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &this->Mousepad_Effect, nullptr);
}
BOOL Chroma_Implementation::applyKeyboardEffect()
{
	return CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &this->Keyboard_Effect, nullptr);
}
BOOL Chroma_Implementation::applyKeypadEffect() {
	return CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &this->Keypad_Effect, nullptr);
}
BOOL Chroma_Implementation::applyHeadsetEffect() {
	return CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_CUSTOM, &this->Headset_Effect, nullptr);
}
//Constants
size_t  Chroma_Implementation::Keyboard_MaxCol()
{
	return ChromaSDK::Keyboard::MAX_COLUMN;
}
size_t  Chroma_Implementation::Keyboard_MaxRow()
{
	return ChromaSDK::Keyboard::MAX_ROW;
}
size_t Chroma_Implementation::Keyboard_MaxLED() {
	return ChromaSDK::Keyboard::MAX_KEYS;
}
size_t  Chroma_Implementation::Mouse_MaxRow()
{
	return ChromaSDK::Mouse::MAX_ROW;
}

size_t  Chroma_Implementation::Mouse_MaxCol()
{
	return ChromaSDK::Mouse::MAX_COLUMN;
}
size_t Chroma_Implementation::Mouse_MaxLED() {
	return ChromaSDK::Mouse::MAX_LEDS2;
}
size_t  Chroma_Implementation::Mousepad_MaxLED()
{
	return ChromaSDK::Mousepad::MAX_LEDS;
}
size_t  Chroma_Implementation::Keypad_MaxCol() {
	return ChromaSDK::Keypad::MAX_COLUMN;
}
size_t Chroma_Implementation::Keypad_MaxRow()
{
	return ChromaSDK::Keypad::MAX_ROW;
}
size_t Chroma_Implementation::Keypad_MaxLED() {
	return ChromaSDK::Keypad::MAX_KEYS;
}
size_t Chroma_Implementation::Headset_MaxLED() {
	return ChromaSDK::Headset::MAX_LEDS;
}

BOOL Chroma_Implementation::setKeyboardbyRow(size_t Row, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Keyboard::MAX_COLUMN; i++)
	{
		this->Keyboard_Effect.Color[Row][i] = Color;
	}
	return TRUE;
}
BOOL Chroma_Implementation::setKeyboardbyCol(size_t Col, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Keyboard::MAX_ROW; i++)
	{
		this->Keyboard_Effect.Color[i][Col] = Color;
	}
	return TRUE;

}

BOOL Chroma_Implementation::setMousebyRow(size_t Row, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Mouse::MAX_COLUMN; i++)
	{
		this->Mouse_Effect.Color[Row][i] = Color;
	}
	return TRUE;
}
BOOL Chroma_Implementation::setMousebyCol(size_t Col, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Mouse::MAX_ROW; i++)
	{
		this->Mouse_Effect.Color[i][Col] = Color;
	}
	return TRUE;
}

BOOL Chroma_Implementation::setKeypadbyRow(size_t Row, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Keypad::MAX_COLUMN; i++)
	{
		this->Keyboard_Effect.Color[Row][i] = Color;
	}
	return TRUE;



}
BOOL Chroma_Implementation::setKeypadbyCol(size_t Col, COLORREF Color)
{
	for (size_t i = 0; i < ChromaSDK::Keypad::MAX_ROW; i++)
	{
		this->Keyboard_Effect.Color[i][Col] = Color;
	}
	return TRUE;



}

BOOL Chroma_Implementation::clearKeyboardEffect()
{
	for (size_t row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++)
		{
			this->Keyboard_Effect.Color[row][col] = NULL;
		}
	}
	return TRUE;
}

BOOL Chroma_Implementation::clearKeypadEffect()
{
	for (size_t row = 0; row < ChromaSDK::Keypad::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keypad::MAX_COLUMN; col++)
		{
			this->Keypad_Effect.Color[row][col] = NULL;
		}
	}

	return TRUE;
}

BOOL Chroma_Implementation::clearMouseEffect()
{
	for (size_t row = 0; row < ChromaSDK::Mouse::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Mouse::MAX_COLUMN; col++)
		{
			this->Mouse_Effect.Color[row][col] = NULL;
		}

	}
	return TRUE;
}

BOOL Chroma_Implementation::clearMousepadEffect()
{
	for (size_t led = 0; led < ChromaSDK::Mousepad::MAX_LEDS; led++)
	{
		this->Mousepad_Effect.Color[led] = NULL;
	}

	return TRUE;
}

BOOL Chroma_Implementation::clearHeadsetEffect()
{
	for (size_t led = 0; led < ChromaSDK::Headset::MAX_LEDS; led++)
	{
		this->Headset_Effect.Color[led] = NULL;
	}

	return TRUE;
}



bool Chroma_Implementation::testandsetColor(PyObject *Color, COLORREF &color)
{
	if (PyTuple_Size(Color) < 3 || PyTuple_Size(Color) > 3)
	{
		return false;
	}
	int R;
	int B;
	int G;

	try {
		R = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(Color, 0)));

		G = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(Color, 1)));


		B = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(Color, 2)));

	}catch(...)
	{
		return false;
	}
	if (R < 0 || R > 255)
	{
		return false;
	}
	if (G < 0 || G > 255)
	{
		return false;
	}
	if (B < 0 || B > 255)
	{
		return false;
	}
	color = RGB(R, G, B);
	return true;
}



BOOL Chroma_Implementation::setKeyboardReactive(size_t Duration, COLORREF Color) {

	ChromaSDK::Keyboard::REACTIVE_EFFECT_TYPE Reactive_Effect = {};

	Reactive_Effect.Color = Color;
	switch (Duration) {
	case 0:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_NONE;
		break;
	case 1:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_SHORT;
		break;
	case 2:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_MEDIUM;
		break;
	case 3:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_LONG;
		break;
	default:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_INVALID;
		break;
	}


	CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_REACTIVE, &Reactive_Effect, nullptr);


	return TRUE;

}

BOOL Chroma_Implementation::setKeypadReactive(size_t Duration, COLORREF Color) {
	ChromaSDK::Keypad::REACTIVE_EFFECT_TYPE Reactive_Effect = {};

	Reactive_Effect.Color = Color;
	switch (Duration) {
	case 0:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_NONE;
		break;
	case 1:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_SHORT;
		break;
	case 2:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_MEDIUM;
		break;
	case 3:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_LONG;
		break;
	default:
		Reactive_Effect.Duration = Reactive_Effect.DURATION_INVALID;
		break;
	}


	CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_REACTIVE, &Reactive_Effect, nullptr);


	return TRUE;
}


BOOL Chroma_Implementation::setKeyboardWave(size_t direction) {


	ChromaSDK::Keyboard::WAVE_EFFECT_TYPE Wave_Effect = {};

	switch (direction) {
	case 0:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_NONE;
		break;
	case 1:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_LEFT_TO_RIGHT;
		break;
	case 2:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_RIGHT_TO_LEFT;
		break;
	default:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_INVALID;
		break;
	}

	CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_WAVE, &Wave_Effect, nullptr);

	return TRUE;

}

BOOL Chroma_Implementation::setKeypadWave(size_t direction) {


	ChromaSDK::Keypad::WAVE_EFFECT_TYPE Wave_Effect = {};

	switch (direction) {
	case 0:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_NONE;
		break;
	case 1:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_LEFT_TO_RIGHT;
		break;
	case 2:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_RIGHT_TO_LEFT;
		break;
	default:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_INVALID;
		break;
	}

	CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_WAVE, &Wave_Effect, nullptr);

	return TRUE;

}

BOOL Chroma_Implementation::setMouseWave(size_t direction) {


	ChromaSDK::Mouse::WAVE_EFFECT_TYPE Wave_Effect = {};

	switch (direction) {

	case 1:
		Wave_Effect.Direction = Wave_Effect.FRONT_TO_BACK;
		break;
	case 2:
		Wave_Effect.Direction = Wave_Effect.BACK_TO_FRONT;
		break;
	default:
		;
	}

	CreateMouseEffect(ChromaSDK::Mouse::CHROMA_WAVE, &Wave_Effect, nullptr);

	return TRUE;

}

BOOL Chroma_Implementation::setMousepadWave(size_t direction) {


	ChromaSDK::Mousepad::WAVE_EFFECT_TYPE Wave_Effect = {};

	switch (direction) {
	case 0:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_NONE;
		break;
	case 1:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_LEFT_TO_RIGHT;
		break;
	case 2:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_RIGHT_TO_LEFT;
		break;
	default:
		Wave_Effect.Direction = Wave_Effect.DIRECTION_INVALID;
		break;
	}

	CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_WAVE, &Wave_Effect, nullptr);

	return TRUE;

}

BOOL Chroma_Implementation::setKeyboardBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Keyboard::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) {
		Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS;
	}

	CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_BREATHING, &Breathing_Effect, nullptr);

	return TRUE;
}
BOOL Chroma_Implementation::setKeypadBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Keypad::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) {
		Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS;
	}

	CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_BREATHING, &Breathing_Effect, nullptr);

	return TRUE;
}
BOOL Chroma_Implementation::setMouseBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Mouse::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) {
		Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS;
	}

	CreateMouseEffect(ChromaSDK::Mouse::CHROMA_BREATHING, &Breathing_Effect, nullptr);

	return TRUE;
}
BOOL Chroma_Implementation::setMousepadBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Mousepad::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) {
		Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS;
	}

	CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_BREATHING, &Breathing_Effect, nullptr);

	return TRUE;
}
BOOL Chroma_Implementation::setHeadsetBreathing(COLORREF first) {
	ChromaSDK::Headset::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	Breathing_Effect.Color = first;


	CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_BREATHING, &Breathing_Effect, nullptr);

	return TRUE;
}

