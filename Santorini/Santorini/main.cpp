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

	if (connectionType == 's')
	{
		SERVER.StartServer();
	}
	else if (connectionType == 'c')
	{
		CLIENT.StartClient(PORT);
	}

	
	Game g;

	g.StartGame();
	////RenderFunction();
	g.MainGameLoop();

	return 0;
}