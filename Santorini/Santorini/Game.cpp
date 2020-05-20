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

		switch (runningState)
		{
		case GameStates::PlayState:
			Play();
			break;

		case GameStates::WinState:
			Winner();
			break;

		case GameStates::LoseState:
			Loser();
			break;

		case GameStates::ExitState:
			return;

		default:
			break;
		}

		window.display();
	}
}

void Game::Play()
{
	world->Update();
	world->Draw();
}

void Game::Winner()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		runningState = GameStates::PlayState;
		world->Setup();
	}
}

void Game::Loser()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		runningState = GameStates::PlayState;
		delete world;
		world = new World(window, this);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		std::cout << "Terminate" << std::endl;
		runningState = GameStates::ExitState;
	}
}