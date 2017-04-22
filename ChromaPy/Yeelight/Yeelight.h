#pragma once
#include "SFML/Network.hpp"
#include "json.hpp"
#include <Windows.h>


using namespace nlohmann;
using namespace std;
extern sf::TcpSocket TCP_SOCKET;

class Yeelight {
private:
	string name;
	string IP;

	string send_cmd(string cmd);
	string receive();
	bool connect();
	bool disconnect();
	bool checkresult(string returnvalue, string compare);
public:
	Yeelight() {};
	Yeelight(string ip) : IP(ip) {};
	~Yeelight() {};


	bool available();
	bool power(string state);
	bool color(COLORREF color);
	bool brightness(int percentage);
	void changeip(string ip);

	bool getPowerState();
	size_t getRGB();
	size_t getBrightness();
	string getName();


	bool  operator==(const Yeelight b) const
	{
		if (!(this->IP.compare(b.IP))) { return true; }
		else { return false; }
	}
};
