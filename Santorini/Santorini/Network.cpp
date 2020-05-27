#include "Network.h"

Network::Network(std::string& ip, unsigned int& players)
{
	s_IPAddress = ip;
	numPlayers = players;
}
bool Network::connectClient()
{
	if (!client.StartClient(PORT))
	{
		std::cerr << "failed to connect to client" << std::endl;
		return false;
	}
	return true;
}

bool Network::StartGame()
{
	if (numPlayers == 2)
	{
		return true;
	}
	return false;
}