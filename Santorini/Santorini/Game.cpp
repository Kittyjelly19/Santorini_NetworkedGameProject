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

void Game::Run()
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

		switch (state)
		{
		case GameState::PlayState:
			Play();
			break;

		case GameState::WinState:
			Victory();
			break;

		case GameState::LoseState:
			Defeat();
			break;

		case GameState::Exit:
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

void Game::Victory()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		state = GameState::PlayState;
		world->Setup();
	}
}

void Game::Defeat()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		state = GameState::PlayState;
		delete world;
		world = new World(window, this);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		std::cout << "Terminate" << std::endl;
		state = GameState::Exit;
	}
}