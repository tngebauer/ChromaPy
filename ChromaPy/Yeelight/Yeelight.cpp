#include "Yeelight.h"

bool Yeelight::connect() {

	if (TCP_SOCKET.connect(this->IP, 55443) == sf::Socket::Status::Done) { return true; }
	else { return false; }
}

bool Yeelight::disconnect() {
	TCP_SOCKET.disconnect();
	return true;
}

string Yeelight::receive() {
	char buffer[1024];
	std::size_t received = 0;
	TCP_SOCKET.receive(buffer, sizeof(buffer), received);
	return buffer;
}

string Yeelight::send_cmd(string cmd) {
	this->connect();
	if (!(TCP_SOCKET.send(cmd.c_str(), cmd.size() + 1) == sf::Socket::Status::Done)) { throw "OMG AN ERROR OCCURED"; }
	string result = this->receive();
	result = result.substr(0, result.find("}")+1);
	this->disconnect();
	return result;
}

bool Yeelight::power(string state) {
	string cmd;
	if (!state.compare("on")) { cmd = "{\"id\":1,\"method\":\"set_power\", \"params\":[\"on\", \"smooth\", 500]}\r\n"; }
	else if (!state.compare("off")) { cmd = "{\"id\":1,\"method\":\"set_power\", \"params\":[\"off\", \"smooth\", 500]}\r\n"; }
	else { return false; }
	
	return checkresult(this->send_cmd(cmd), "ok");


}

bool Yeelight::checkresult(string returnvalue, string compare) {
	json result = json::parse(returnvalue.c_str());
	string tocompare = result["result"][0];
	if (!tocompare.compare(compare)) { return true; }
	else { return false; }
}


bool Yeelight::color(COLORREF color) {
	int green, red, blue;
	red = GetRValue(color);
	green = GetGValue(color);
	blue = GetBValue(color);

	if (red > 255 || red < 0) { return false; }
	if (green > 255 || green < 0) { return false; }
	if (blue > 255 || blue < 0) { return false; }

	int Web_color = (red * 65536) + (green * 256) + blue;

	string cmd = "{\"id\":1,\"method\":\"set_rgb\",\"params\":[";
	cmd.append(to_string(Web_color));
	cmd.append(",\"smooth\", 100]}\r\n");

	return checkresult(this->send_cmd(cmd), "ok");
}

bool Yeelight::brightness(int percentage) {

	if (percentage > 100 || percentage < 0) { return false; }

	string cmd = "{\"id\":1,\"method\":\"set_bright\",\"params\":[";
	cmd.append(to_string(percentage));
	cmd.append(",\"smooth\", 500]}\r\n");
	return checkresult(this->send_cmd(cmd), "ok");
}

void Yeelight::changeip(string ip) {
	this->IP = ip;
}

bool Yeelight::available() {
	string cmd = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"power\"]}\r\n";
	json result = json::parse(this->send_cmd(cmd).c_str());
	if (result["id"] == 1) { return true; }
	else { return false; }
}

bool Yeelight::getPowerState() {
	string cmd = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"power\"]}\r\n";
	return checkresult(this->send_cmd(cmd), "on");
}

string Yeelight::getName() {
	string cmd = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"name\"]}\r\n";
	json result = json::parse(this->send_cmd(cmd).c_str());
	return result["result"][0];
}

size_t Yeelight::getBrightness() {
	string cmd = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"bright\"]}\r\n";
	json result = json::parse(this->send_cmd(cmd).c_str());
	string tmp = result["result"][0];
	return stoi(tmp);
}

size_t Yeelight::getRGB() {
	string cmd = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"rgb\"]}\r\n";
	json result = json::parse(this->send_cmd(cmd).c_str());
	string tmp = result["result"][0];
	return stoi(tmp);
}

