#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Message.h"
#include "Util.h"

#define PORT (unsigned short) 4200





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
	static Client* client;
	static Client& GetCInstance();

	bool StartClient(unsigned short port);
	bool ready;
	

	void RunClientListener();
	void ConnectClientToHost();
	void RequestConnection(const std::string& ip);
	void FindClients();

	/*void FindClients();*/
	void SendMsg();
	bool ReceiveMsg();


	
};
#define CLIENT Client::GetCInstance()