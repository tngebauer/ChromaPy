#include "Header\ChromaSDK.h"


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



RZRESULT Chroma_Implementation::IsDeviceConnected(RZDEVICEID DeviceId)
{
	if (QueryDevice != nullptr)
	{
		ChromaSDK::DEVICE_INFO_TYPE DeviceInfo = {};
		RZRESULT  Result = QueryDevice(DeviceId, DeviceInfo);

		if (DeviceInfo.Connected == 1) { return true; }
		else { return false; }


	}

	return false;
}


Chroma_Implementation::Chroma_Implementation() :ChromaModule(nullptr)
{

}
Chroma_Implementation::~Chroma_Implementation()
{
}

RZRESULT Chroma_Implementation::Initialize()
{
	if (ChromaModule == nullptr)
	{
		ChromaModule = LoadLibrary(CHROMASDKDLL);
		if (ChromaModule == nullptr)
		{
			return FALSE;
		}
	}

	if (Init == nullptr)
	{
		RZRESULT  Result = RZRESULT_INVALID;
		Init = reinterpret_cast<INIT>(GetProcAddress(ChromaModule, "Init"));
		if (Init)
		{
			Result = Init();
			if (Result == RZRESULT_SUCCESS)
			{
				CreateEffect = reinterpret_cast<CREATEEFFECT>(GetProcAddress(ChromaModule, "CreateEffect"));
				CreateKeyboardEffect = reinterpret_cast<CREATEKEYBOARDEFFECT>(GetProcAddress(ChromaModule, "CreateKeyboardEffect"));
				CreateMouseEffect = reinterpret_cast<CREATEMOUSEEFFECT>(GetProcAddress(ChromaModule, "CreateMouseEffect"));
				CreateHeadsetEffect = reinterpret_cast<CREATEHEADSETEFFECT>(GetProcAddress(ChromaModule, "CreateHeadsetEffect"));
				CreateMousepadEffect = reinterpret_cast<CREATEMOUSEPADEFFECT>(GetProcAddress(ChromaModule, "CreateMousepadEffect"));
				CreateKeypadEffect = reinterpret_cast<CREATEKEYPADEFFECT>(GetProcAddress(ChromaModule, "CreateKeypadEffect"));
				SetEffect = reinterpret_cast<SETEFFECT>(GetProcAddress(ChromaModule, "SetEffect"));
				DeleteEffect = reinterpret_cast<DELETEEFFECT>(GetProcAddress(ChromaModule, "DeleteEffect"));
				QueryDevice = reinterpret_cast<QUERYDEVICE>(GetProcAddress(ChromaModule, "QueryDevice"));

				if (CreateEffect && CreateKeyboardEffect && CreateMouseEffect && CreateHeadsetEffect && CreateMousepadEffect && CreateKeypadEffect && SetEffect && DeleteEffect && QueryDevice) { return TRUE; }
				else { return FALSE; }
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
		if (CreateKeyboardEffect) { CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr); }
		if (CreateMousepadEffect) { CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr); }
		if (CreateMouseEffect) { CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr); }
		if (CreateHeadsetEffect) { CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr); }
		if (CreateKeypadEffect) { CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr); }
		break;
	case 1:
		if (CreateKeyboardEffect) { CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr); }
		break;
	case 2:
		if (CreateMousepadEffect) { CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr); }
		break;
	case 3:
		if (CreateMouseEffect) { CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr); }
		break;
	case 4:
		if (CreateHeadsetEffect) { CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr); }
		break;
	case 5:
		if (CreateKeypadEffect) { CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr); }
		break;
	default: ;
	}
}

void Chroma_Implementation::ConnectedDevices(vector<char*> &devices) 
{
	if (Chroma.IsDeviceConnected(ChromaSDK::BLACKWIDOW_CHROMA)) { devices.push_back("BLACKWIDOW_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::BLACKWIDOW_CHROMA_TE)) { devices.push_back("BLACKWIDOW_CHROMA_TE"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::BLACKWIDOW_X_CHROMA)) { devices.push_back("BLACKWIDOW_X_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::BLACKWIDOW_X_TE_CHROMA)) { devices.push_back("BLACKWIDOW_X_CHROMA_TE"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::DEATHSTALKER_CHROMA)) { devices.push_back("DEATHSTALKER_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::OVERWATCH_KEYBOARD)) { devices.push_back("BLACKWIDOW_CHROMA_OVERWATCH"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::ORNATA_CHROMA)) { devices.push_back("ORNATA_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::BLADE_STEALTH)) { devices.push_back("BLADE_STEALTH"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::BLADE)) { devices.push_back("BLADE"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::MAMBA_CHROMA)) { devices.push_back("MAMBA_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::MAMBA_CHROMA_TE)) { devices.push_back("MAMBA_CHROMA_TE"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::DEATHADDER_CHROMA)) { devices.push_back("DEATHADDER_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::DIAMONDBACK_CHROMA)) { devices.push_back("DIAMONDBACK_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::NAGA_EPIC_CHROMA)) { devices.push_back("NAGA_EPIC_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::NAGA_CHROMA)) { devices.push_back("NAGA_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::OROCHI_CHROMA)) { devices.push_back("OROCHI_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::NAGA_HEX_CHROMA)) { devices.push_back("NAGA_HEX_CHROMA "); }
	if (Chroma.IsDeviceConnected(ChromaSDK::KRAKEN71_CHROMA)) { devices.push_back("KRAKEN71_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::MANOWAR_CHROMA)) { devices.push_back("MANOWAR_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::FIREFLY_CHROMA)) { devices.push_back("FIREFLY_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::TARTARUS_CHROMA)) { devices.push_back("TARTARUS_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::ORBWEAVER_CHROMA)) { devices.push_back("ORBWEAVER_CHROMA"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::LENOVO_Y900)) { devices.push_back("LENOVO_Y900"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::LENOVO_Y27)) { devices.push_back("LENOVO_Y27"); }
	if (Chroma.IsDeviceConnected(ChromaSDK::CORE_CHROMA)) { devices.push_back("CORE_CHROMA"); }
	//add new Chroma Devices here
}



//set static effect to all/specific devices
PyObject* Chroma_Implementation::set_all(COLORREF Color)
{
	this->setKeyboard(Color);
	this->setMouse(Color);
	this->setMousepad(Color);
	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setKeyboard(COLORREF Color){
	for (UINT row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++) {
			this->Keyboard_Effect.Color[row][col] = Color;
		}
	}

	return PyUnicode_FromString("Success");
}
PyObject* Chroma_Implementation::setMousepad(COLORREF Color){
	for (UINT count = 0; count < ChromaSDK::Mousepad::MAX_LEDS; count++) {
		this->Mousepad_Effect.Color[count] = Color;
	}

	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setMouse(COLORREF Color){
	for (UINT row = 0; row < ChromaSDK::Mouse::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Mouse::MAX_COLUMN; col++) {
			this->Mouse_Effect.Color[row][col] = Color;
		}
	}

	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setKeypad(COLORREF Color) {
	for (UINT row = 0; row < ChromaSDK::Keypad::MAX_ROW; row++) {
		for (UINT col = 0; col < ChromaSDK::Keypad::MAX_COLUMN; col++) {
			this->Keypad_Effect.Color[row][col] = Color;
		}
	}

	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setHeadset(COLORREF Color) {
	for (UINT count = 0; count < ChromaSDK::Headset::MAX_LEDS; count++) {
		this->Headset_Effect.Color[count] = Color;
	}

	return PyUnicode_FromString("Success");;
}

//Set Keyboard by x- and y-cords
PyObject* Chroma_Implementation::setKeyboardbyCord(size_t x, size_t y, COLORREF Color){
	if (y < ChromaSDK::Keyboard::MAX_ROW && x < ChromaSDK::Keyboard::MAX_COLUMN){
		this->Keyboard_Effect.Color[y][x] = Color;
		return PyUnicode_FromString("Success");;
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error!");
		return nullptr;
	}
}
//Set Mouse by x- and y-cords
PyObject* Chroma_Implementation::setMousebyCord(size_t x, size_t y, COLORREF Color){
	if (y < ChromaSDK::Mouse::MAX_ROW && x < ChromaSDK::Mouse::MAX_COLUMN){
		this->Mouse_Effect.Color[y][x] = Color;
		return PyUnicode_FromString("Success");;
	}
	else{
		PyErr_SetString(SyntaxError, "ChromaSDK Error!");
		return nullptr;
	}
}
//set Mousepad by LEDs
PyObject* Chroma_Implementation::setMousepadbyLED(size_t led, COLORREF Color){
	if (led < ChromaSDK::Mousepad::MAX_LEDS){
		this->Mousepad_Effect.Color[led] = Color;
		return PyUnicode_FromString("Success");;
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error!");
		return nullptr;
	}

}

PyObject* Chroma_Implementation::setKeypadbyCord(size_t x, size_t y, COLORREF Color) {
	if (y < ChromaSDK::Keypad::MAX_ROW && x < ChromaSDK::Keypad::MAX_COLUMN){
		this->Keypad_Effect.Color[y][x] = Color;
		return PyUnicode_FromString("Success");;
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error!");
		return nullptr;
	}


}

PyObject* Chroma_Implementation::setHeadsetbyLED(size_t led, COLORREF Color) {
	if (led < ChromaSDK::Headset::MAX_LEDS) {
		this->Headset_Effect.Color[led] = Color;
		return PyUnicode_FromString("Success");;
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error!");
		return nullptr;
	}
}
//Apply effects
PyObject* Chroma_Implementation::applyMouseEffect(){
	return CheckError(CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &this->Mouse_Effect, nullptr));
}
PyObject* Chroma_Implementation::applyMousepadEffect(){
	return CheckError(CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &this->Mousepad_Effect, nullptr));
}
PyObject* Chroma_Implementation::applyKeyboardEffect(){
	return CheckError(CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &this->Keyboard_Effect, nullptr));
}
PyObject* Chroma_Implementation::applyKeypadEffect() {
	return CheckError(CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &this->Keypad_Effect, nullptr));
}
PyObject* Chroma_Implementation::applyHeadsetEffect() {
	return CheckError(CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_CUSTOM, &this->Headset_Effect, nullptr));
}
//Constants
size_t  Chroma_Implementation::Keyboard_MaxCol() { return ChromaSDK::Keyboard::MAX_COLUMN; }
size_t  Chroma_Implementation::Keyboard_MaxRow() { return ChromaSDK::Keyboard::MAX_ROW; }
size_t Chroma_Implementation::Keyboard_MaxLED() { return ChromaSDK::Keyboard::MAX_KEYS; }
size_t  Chroma_Implementation::Mouse_MaxRow(){ return ChromaSDK::Mouse::MAX_ROW; }
size_t  Chroma_Implementation::Mouse_MaxCol(){ return ChromaSDK::Mouse::MAX_COLUMN; }
size_t Chroma_Implementation::Mouse_MaxLED() { return ChromaSDK::Mouse::MAX_LEDS2; }
size_t  Chroma_Implementation::Mousepad_MaxLED(){ return ChromaSDK::Mousepad::MAX_LEDS; }
size_t  Chroma_Implementation::Keypad_MaxCol() { return ChromaSDK::Keypad::MAX_COLUMN; }
size_t Chroma_Implementation::Keypad_MaxRow(){ return ChromaSDK::Keypad::MAX_ROW; }
size_t Chroma_Implementation::Keypad_MaxLED() { return ChromaSDK::Keypad::MAX_KEYS; }
size_t Chroma_Implementation::Headset_MaxLED() { return ChromaSDK::Headset::MAX_LEDS; }

PyObject* Chroma_Implementation::setKeyboardbyRow(size_t Row, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Keyboard::MAX_COLUMN; i++)
	{
		this->Keyboard_Effect.Color[Row][i] = Color;
	}
	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setKeyboardbyCol(size_t Col, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Keyboard::MAX_ROW; i++)
	{
		this->Keyboard_Effect.Color[i][Col] = Color;
	}
	return PyUnicode_FromString("Success");;

}

PyObject* Chroma_Implementation::setMousebyRow(size_t Row, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Mouse::MAX_COLUMN; i++)
	{
		this->Mouse_Effect.Color[Row][i] = Color;
	}
	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setMousebyCol(size_t Col, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Mouse::MAX_ROW; i++)
	{
		this->Mouse_Effect.Color[i][Col] = Color;
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::setKeypadbyRow(size_t Row, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Keypad::MAX_COLUMN; i++)
	{
		this->Keyboard_Effect.Color[Row][i] = Color;
	}
	return PyUnicode_FromString("Success");;
}
PyObject* Chroma_Implementation::setKeypadbyCol(size_t Col, COLORREF Color){
	for (size_t i = 0; i < ChromaSDK::Keypad::MAX_ROW; i++)
	{
		this->Keyboard_Effect.Color[i][Col] = Color;
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::clearKeyboardEffect(){
	for (size_t row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++)
		{
			this->Keyboard_Effect.Color[row][col] = NULL;
		}
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::clearKeypadEffect(){
	for (size_t row = 0; row < ChromaSDK::Keypad::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keypad::MAX_COLUMN; col++){
			this->Keypad_Effect.Color[row][col] = NULL;
		}
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::clearMouseEffect(){
	for (size_t row = 0; row < ChromaSDK::Mouse::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Mouse::MAX_COLUMN; col++){
			this->Mouse_Effect.Color[row][col] = NULL;
		}
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::clearMousepadEffect(){
	for (size_t led = 0; led < ChromaSDK::Mousepad::MAX_LEDS; led++){
		this->Mousepad_Effect.Color[led] = NULL;
	}
	return PyUnicode_FromString("Success");;
}

PyObject* Chroma_Implementation::clearHeadsetEffect(){
	for (size_t led = 0; led < ChromaSDK::Headset::MAX_LEDS; led++){
		this->Headset_Effect.Color[led] = NULL;
	}
	return PyUnicode_FromString("Success");;
}

bool Chroma_Implementation::Colortest(PyObject *InputColor, COLORREF &color){
	if (PyTuple_Size(InputColor) != 3) { return false; }
	int R, G, B;

	try {
		R = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(InputColor, 0)));
		G = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(InputColor, 1)));
		B = static_cast<int>(PyLong_AsLong(PyTuple_GetItem(InputColor, 2)));
	}
	catch(...){ return false; }

	if (R < 0 || R > 255){ return false; }
	if (G < 0 || G > 255){ return false; }
	if (B < 0 || B > 255){ return false; }
	color = RGB(R, G, B);
	return true;
}

PyObject* Chroma_Implementation::setKeyboardReactive(size_t Duration, COLORREF Color) {

	ChromaSDK::Keyboard::REACTIVE_EFFECT_TYPE Reactive_Effect;

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
	return CheckError(CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_REACTIVE, &Reactive_Effect, nullptr));
	
}

PyObject* Chroma_Implementation::setKeypadReactive(size_t Duration, COLORREF Color) {
	ChromaSDK::Keypad::REACTIVE_EFFECT_TYPE Reactive_Effect;

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

	return CheckError(CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_REACTIVE, &Reactive_Effect, nullptr));

}


PyObject* Chroma_Implementation::setKeyboardWave(size_t direction) {


	ChromaSDK::Keyboard::WAVE_EFFECT_TYPE Wave_Effect;

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

	return CheckError(CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_WAVE, &Wave_Effect, nullptr));


}

PyObject* Chroma_Implementation::setKeypadWave(size_t direction) {


	ChromaSDK::Keypad::WAVE_EFFECT_TYPE Wave_Effect;

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

	return CheckError(CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_WAVE, &Wave_Effect, nullptr));

}

PyObject* Chroma_Implementation::setMouseWave(size_t direction) {


	ChromaSDK::Mouse::WAVE_EFFECT_TYPE Wave_Effect;

	switch (direction) {
	case 1:
		Wave_Effect.Direction = Wave_Effect.FRONT_TO_BACK;
		break;
	case 2:
		Wave_Effect.Direction = Wave_Effect.BACK_TO_FRONT;
		break;
	default:
		return nullptr;
	}

	return CheckError(CreateMouseEffect(ChromaSDK::Mouse::CHROMA_WAVE, &Wave_Effect, nullptr));

}

PyObject* Chroma_Implementation::setMousepadWave(size_t direction) {


	ChromaSDK::Mousepad::WAVE_EFFECT_TYPE Wave_Effect;

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

	return CheckError(CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_WAVE, &Wave_Effect, nullptr));

}

PyObject* Chroma_Implementation::setKeyboardBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Keyboard::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) {
		Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS;
	}

	return CheckError(CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_BREATHING, &Breathing_Effect, nullptr));

}
PyObject* Chroma_Implementation::setKeypadBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Keypad::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) { Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS; }

	return CheckError(CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_BREATHING, &Breathing_Effect, nullptr));

}
PyObject* Chroma_Implementation::setMouseBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Mouse::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}

	if (mode == 0) { Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS; }

	return CheckError(CreateMouseEffect(ChromaSDK::Mouse::CHROMA_BREATHING, &Breathing_Effect, nullptr));

}
PyObject* Chroma_Implementation::setMousepadBreathing(bool mode, COLORREF first, COLORREF second) {
	ChromaSDK::Mousepad::BREATHING_EFFECT_TYPE Breathing_Effect = {};

	if (mode == 1) {
		Breathing_Effect.Type = Breathing_Effect.TWO_COLORS;
		Breathing_Effect.Color1 = first;
		Breathing_Effect.Color2 = second;
	}
	if (mode == 0) { Breathing_Effect.Type = Breathing_Effect.RANDOM_COLORS; }

	return CheckError(CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_BREATHING, &Breathing_Effect, nullptr));

}
PyObject* Chroma_Implementation::setHeadsetBreathing(COLORREF first) {
	ChromaSDK::Headset::BREATHING_EFFECT_TYPE Breathing_Effect;

	Breathing_Effect.Color = first;

	return CheckError(CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_BREATHING, &Breathing_Effect, nullptr));
}

PyObject* Chroma_Implementation::CheckError(RZRESULT result) {
	if (result == RZRESULT_SUCCESS) {
		return PyUnicode_FromString("Success");
	}
	else {
		PyErr_SetString(SyntaxError, "ChromaSDK Error! Error-Code: " + result);
		return nullptr;
	}
}