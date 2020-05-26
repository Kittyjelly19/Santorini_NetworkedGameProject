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
	//return server instance.
	return *server;
}

//Main server function.
void StartServer()
{
	Queue <Message> queue;
	bool stopServerListening = false;

	while (!stopServerListening)
	{
		Message m = queue.pop();
		MsgConstruct msg;
		ReadMessage(m, msg);

		std::shared_ptr<Acceptor> acceptor = std::make_shared<Acceptor>(queue);
		std::thread(&Acceptor::ConnectionAccepted, acceptor).detach();

		

		//switch statement for message types. 
		switch (msg.msgtype)
		{
		case MessageType::RegisterMsg:
			std::string reg;
			reg = msg.data;
			std::cout << "server message pop: " << reg << std::endl;
			break;
		}
	}
	
}
