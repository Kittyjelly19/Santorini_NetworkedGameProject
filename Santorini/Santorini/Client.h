#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Message.h"


#define C_PORT (unsigned short) 4200





class Client
{
private:

	sf::IpAddress ipAdress;

public:

	Client();
	~Client();
	sf::TcpSocket cSocket;
	static Client* client;
	static Client& GetCInstance();

	bool StartClient(unsigned short port);

	void SendMsg();
	bool ReceiveMsg();

	bool RunningClient(unsigned short port);
	
};
#define CLIENT Client::GetCInstance()