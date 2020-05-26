#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Message.h"
#include "Util.h"

#define PORT (unsigned short) 4300





class Client
{
private:

	sf::IpAddress s_IPAdress;
	bool isClientsTurn = false;
	bool isHostingLocally = false;
	bool ContinueListening = true;
	



public:

	Client();
	~Client();
	sf::TcpSocket socket;

	bool StartClient(sf::IpAddress& ip);
	bool ready;


	void RunClientListener();
	void ConnectClientToHost();
	void RequestConnection(const std::string& ip);
	void FindClients();

	/*void FindClients();*/
	void SendMsg();
	bool ReceiveMsg();


	
};