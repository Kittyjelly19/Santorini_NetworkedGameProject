//#include "Server.h"
//#include "Util.h"
//#include <SFML/Network.hpp>
//#include <cstring>
//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <thread>
//
//
//
//int main()
//{
//	sf::TcpListener listener;
//	sf::UdpSocket s_UDP;
//
//	//Binding UDP socket to port. 
//	if (s_UDP.bind(UPORT) != sf::Socket::Done)
//	{
//		std::cerr << "Error binding to Server UDP port\n";
//		return 1;
//	}
//}

#include "Server.h"
#include <iostream>
#include <sstream>
#include <thread>

Server* Server::server{ nullptr };

//Server Constructor. 
Server::Server()
{
	s_IPAddress = s_IPAddress.getLocalAddress();
}

//if server instance is not assigned to anything, create a new server instance. 
Server& Server::GetSInstance()
{
	if (server == nullptr)
	{
		server = new Server;
	}
	return *server;
}

void StartServer()
{
	Queue <Message> queue;
	bool stopServerListening = false;

	do
	{
		std::shared_ptr<Acceptor> accepter = std::make_shared<Acceptor>(queue);
		std::thread(&Acceptor::AcceptConnection, accepter).detach();

		Message m = queue.pop();
		MsgConstruct msg;

		ReadMessage(m, msg);

		switch (msg.msgtype)
		{
		case MessageType::StartGameMsg:
			std::string startgame;
			startgame = msg.data;
			std::cout << "server message pop: " << startgame << std::endl;
			break;
		}
	} while (!stopServerListening);
}
