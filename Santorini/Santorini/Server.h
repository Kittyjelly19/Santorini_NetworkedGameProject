//#pragma once
//#include <SFML/Network.hpp>
//#include "Client.h"

//using namespace sf;
//
////Assigning a port number to server
//const unsigned short ServerPortID = 1500;
//
//
//
////Server Packet
////enum ServerPacket
////{
////	BroadcastMessage,
////	StartingState,
////	PlayerTurnMove,
////	UpdateBoards,
////	PlayerJoin,
////	PlayerLeave,
////	UpdateClient
////
////};
//
//
//
//
//
//class Server
//{
//private:
//	SocketSelector c_selector;
//	std::vector<TcpSocket*> c_Sockets;
//public:
//	/*void RunServerListen();
//	void InstigateGame();*/
//};

#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Message.h"
#include "Client.h"
#include "Acceptor.h"

//Defining server port. 
#define PORT (unsigned short) 4500



class Server
{
	Server();
	~Server();

	
public:
	
	void StartServer();

	//Getting a static instance of the server. 
	static Server& GetSInstance();

	//Adding a client to the server.
	/*void AddClient(unsigned short& clientID, std::shared_ptr<sf::TcpSocket>& clientSocket) { clients.insert(Client(clientID, clientSocket)); };*/
	
	void SendPacket(MessageType mType, sf::Vector2f pos = sf::Vector2f(0, 0), int ID = -1);
	

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