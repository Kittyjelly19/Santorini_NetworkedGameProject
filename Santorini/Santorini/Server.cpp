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



void Server::StartServer()
{
	Queue <Message> queue;
	bool stopServerListening = false;

	while (!stopServerListening)
	{
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
			std::cout << "server message: " << registration << std::endl;
			break;
		}
	}
}

void Server::StartGame()
{
	sf::Packet packet;
	packet << (int)MessageType::StartGameMsg;
	
	//for (auto& c : clients)
	//{
	//	/*Client* client.SendMsg;*/
	//}
}
//void Server::StartServer()
//{
//	std::thread tcpListenerThread([&]() {
//		sf::TcpListener listener;
//
//		while (clients.size() < 2) {
//			std::cout << "waiting for client" << std::endl;
//			sf::TcpSocket* newClient = new sf::TcpSocket();
//			sf::Packet packet;
//
//			listener.listen(PORT);
//			sf::Socket::Status socketStatus = listener.accept(*newClient);
//
//			while (socketStatus == newClient->Disconnected || socketStatus == newClient->Error) {
//				socketStatus = listener.accept(*newClient);
//			}
//			std::cout << "new client: " << newClient->getRemoteAddress() << std::endl;
//			clients.insert(newClient);
//		}
//		}
//}

//void Server::SendPacket(MessageType mType, sf::Vector2f pos, int ID)
//{
//}