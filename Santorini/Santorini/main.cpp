#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Server.h"
#include "Client.h"
#include <SFML/Network.hpp>
//#include "Menu.h"

int main()
{

	std::cout << "Enter (s) to host server, (c) to join server" << std::endl;
	//std::cin >> ;
	Game g;

	g.StartGame();
	//RenderFunction();
	g.MainGameLoop();

	return 0;
}