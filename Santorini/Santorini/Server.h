#pragma once
#include <SFML/Network.hpp>
#include "Client.h"

using namespace sf;

//Assigning a port number to server
const unsigned short ServerPortID = 1500;



//Server Packet
//enum ServerPacket
//{
//	BroadcastMessage,
//	StartingState,
//	PlayerTurnMove,
//	UpdateBoards,
//	PlayerJoin,
//	PlayerLeave,
//	UpdateClient
//
//};





class Server
{
private:
	SocketSelector c_selector;
	std::vector<TcpSocket*> c_Sockets;
public:
	/*void RunServerListen();
	void InstigateGame();*/
};

