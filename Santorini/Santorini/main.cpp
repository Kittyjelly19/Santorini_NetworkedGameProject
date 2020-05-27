#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Server.h"
#include "Client.h"
#include "Network.h"
#include <SFML/Network.hpp>


int main()
{
	char connectionType, mode;

	//Whether we want to run as a server or a client
	std::cout << "Enter (s) to host server, (c) to join server" << std::endl;
	std::cin >> connectionType;

	if (connectionType == 's') //if running as a server. 
	{
		SERVER.StartServer();
	}
	else if (connectionType == 'c')//if running as a client. 
	{
		CLIENT.StartClient(C_PORT);
		
	}

	//Game instance. 
	Game g;
	
	//Game.
	g.StartGame();
	g.MainGameLoop();

	return 0;
}