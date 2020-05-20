#pragma once
#include "Client.h"


//Assigning a port number to server
const unsigned short ServerPortID = 1500;



//Server Packet
enum ServerPacket
{
	BroadcastMessage,
	StartingState,
	PlayerTurnMove,
	UpdateBoards,
	PlayerJoin,
	PlayerLeave,
	UpdateClient

};





class Server
{
};

