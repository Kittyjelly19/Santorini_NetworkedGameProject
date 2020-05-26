#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Server.h"
#include "Client.h"
#include <SFML/Network.hpp>


int main()
{

	/*std::cout << "Enter (s) to host server, (c) to join server" << std::endl;*/
	//std::cin >> ;
	SERVER.StartServer();
	Game g;

	g.StartGame();
	//RenderFunction();
	g.MainGameLoop();

	return 0;
}