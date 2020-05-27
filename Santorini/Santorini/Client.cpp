#include "Client.h"
#include "Server.h"
#include <iostream>
#include <sstream>
#include <thread>

Client* Client::client{ nullptr };

Client::Client()
{
}

Client::~Client()
{
}

//Main client function. 
bool Client::StartClient(unsigned short port)
{

	sf::IpAddress server;
	
	while (server == sf::IpAddress::None)
	{//asking user to input the server address while there is no server connected.
		std::cout << "Type the server address: " << std::endl;
		std::cin >> server;
	}
	
	if (cSocket.connect(server, S_PORT) != sf::Socket::Done)
	{
		return false;
		std::cout << "Connected to server" << server << cSocket.getRemotePort() << std::endl;
		return true;
	}
	else
	{
		std::cout << "could not connect to server." << std::endl;
	}
	
}

//Getting instance of client. 
Client& Client:: GetCInstance()
{
	if (client == nullptr)
	{
		client = new Client;
	}
	//return client instance.
	return *client;
}


void Client::SendMsg()
{
	sf::Uint32 id = cSocket.getLocalPort();
	MsgConstruct msg;
	msg.id = id;
	/*std::memcpy(msg.data, msg.msgtype)*/
	sf::Packet packet;
	packet << msg;

	if (cSocket.send(packet) != sf::Socket::Done)
	{
		std::cerr << "Message send failure :( " << std::endl;
		return;
	}
	std::cout << "Message send success :)" << std::endl;
}

bool Client::ReceiveMsg()
{
	return true;
}

