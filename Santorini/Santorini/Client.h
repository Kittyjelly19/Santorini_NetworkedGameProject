#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>




using namespace std;

//Client Packet
enum ClientPacket
{
	PlayerTurn,
	UpdateBoard,
	MoveUpdate,
	GameEvent,
	Exit
};

class Client
{
public:

	Client();
	~Client();

	bool RunningClient(unsigned short port);

private:

	sf::IpAddress s_Name;
	sf::TcpSocket clientSocket;
};