
#include "Server.h"
#include "Client.h"
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


//Main server functionallity.
void Server::StartServer()
{
	Queue <Message> queue;
	bool stopServerListening = false;
	s_IPAddress.getLocalAddress;
	
	
	//displaying server address on server start. 
	std::cout << "Server Address is: " << SERVER.s_IPAddress << std::endl;

	while (!stopServerListening)
	{
		//While server is listening
		std::shared_ptr<Acceptor> acceptor = std::make_shared<Acceptor>(queue);
		std::thread(&Acceptor::ConnectionAccepted, acceptor).detach();

		Message m = queue.pop();
		MsgConstruct msg;
		ReadMessage(m, msg);


		//switch statement for message types. 
		switch (msg.msgtype)
		{
		case MessageType::RegisterMsg:
			std::string registration;
			registration = msg.data;
			std::cout << "MESSAGE: Registration: " << registration << std::endl;
			break;
			
			//case Start game message.
			//break;

			//case place worker message. 
			//break;
		}
	}
}

void Server::StartGame()
{
	sf::Packet packet;
	packet << (int)MessageType::StartGameMsg;
	
}
