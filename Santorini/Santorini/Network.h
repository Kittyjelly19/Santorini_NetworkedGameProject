#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Client.h"

#define PORT (unsigned short) 4500


class Network
{
private:
	sf::IpAddress s_IPAddress;
	Client client;
	

	int numPlayers = 2;
public:
	Network(std::string& ip, unsigned int& players);
	//Connecting the client
	bool connectClient();
	
	//Running the game through the network. 
	bool StartGame();

};

