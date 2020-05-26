#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Client.h"

#define PORT (unsigned short) 4300


class Network
{
private:
	sf::IpAddress s_IPAddress;
	Client client;

	int numPlayers = 0;
public:
	Network(std::string& ip, unsigned int& players);

	bool connectClient();
	bool StartGame();

	void Run();
	void Receive();
	void SendToServer();
};

