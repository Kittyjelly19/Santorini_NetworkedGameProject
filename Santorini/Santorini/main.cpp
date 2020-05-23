#include "Game.h"
#include <SFML/Graphics.hpp>
//#include "Menu.h"

int main()
{
	Game g;

	g.StartGame();
	//RenderFunction();
	g.MainGameLoop();

	return 0;
}