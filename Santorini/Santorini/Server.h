
#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Message.h"
#include "Client.h"
#include "Acceptor.h"

//Defining server port. 
#define S_PORT (unsigned short) 4500



class Server
{
	Server();
	~Server();

	
public:
	
	void StartServer();
	void StartGame();

	//Getting a static instance of the server. 
	static Server& GetSInstance();

	
	

private:
	//Creating an instance of server.
	static Server* server;
		
	//Client map for connected clients. 
	std::map<unsigned short, std::shared_ptr<sf::TcpSocket>> clients;
	
	sf::IpAddress s_IPAddress;
};

//To the server, the client is made up of an unsigned short and a tcp socket. 
typedef std::pair<unsigned short, std::shared_ptr<sf::TcpSocket>> myClient;
#define SERVER Server::GetSInstance()