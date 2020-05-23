#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Santorini")
{
	world = new World(window, this);
}

Game::~Game()
{
	delete world;
}

void Game::StartGame()
{
	world->Setup();
}

void Game::MainGameLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		world->Update();

		window.display();
	}
}

void Game::SetUpGame()
{
	world->Setup();
}
void Game::Play()
{
	world->Update(); 
	world->DrawGameLevel();
}



