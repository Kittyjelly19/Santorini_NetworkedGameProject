#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>




using namespace std;


class Client
{
public:

	Client();
	~Client();

	bool RunningClient(unsigned short port);

private:

	sf::IpAddress s_Name;
	sf::TcpSocket clientSocket;
};