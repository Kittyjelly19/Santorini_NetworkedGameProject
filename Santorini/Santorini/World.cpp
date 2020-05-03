#include "World.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

World::World(sf::RenderWindow& w, Game* g_) : window(w)
{
	srand(time(0));
	window.setFramerateLimit(60);
	Setup();
}

World::~World()
{
}

void World::Setup()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			tiles[i][j].x = i;
			tiles[i][j].y = j;

			tiles[i][j].level = 0;
		}
	}

	builders.push_back(Builder(1, 1, 0));
	builders.push_back(Builder(3, 3, 0));
	builders.push_back(Builder(3, 1, 1));
	builders.push_back(Builder(1, 3, 1));
	/*numPlayers = players;*/

	turn = 0;
}

void World::Update()
{
	DrawHover();


	playerTurn = turn % 2; // Determines which players go it is

	switch (currentAction)
	{
	case PlayerState::Select:
		SelectPlayer(playerTurn);
		break;

	case PlayerState::Move:
		MovePlayer(playerTurn);
		break;

	case PlayerState::Build:
		BuildPlayer();
		break;

	default:
		break;
	}
}

void World::Draw()
{
	window.clear();

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tiles[i][j].Draw(window);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		builders[i].Draw(window);
	}
}

Tile* World::MouseHover()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	int tileI = 0;
	int tileJ = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tiles[i][j].hasOutline = false;

			if (mousePos.x >= tiles[i][j].x * 120 + 5)
			{
				if (i < 4)
				{
					if (mousePos.x <= tiles[i + 1][j].x * 120 + 5)
					{
						tileI = i;
					}
				}
				else
				{
					tileI = i;
				}
			}

			if (mousePos.y >= tiles[i][j].y * 120 + 5)
			{
				if (j < 4)
				{
					if (mousePos.y <= tiles[i][j + 1].y * 120 + 5)
					{
						tileJ = j;
					}
				}
				else
				{
					tileJ = j;
				}
			}
		}
	}

	return &(tiles[tileI][tileJ]);
}

void World::DrawHover()
{
	Tile* currentTile = MouseHover();
	currentTile->hasOutline = true;
}

void World::SelectPlayer(int& player)
{
	bool builderSelected = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseClicked = false;
	}

	if ((!mouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		mouseClicked = true;

		std::cout << "SELECT" << std::endl;
		std::cout << playerTurn << std::endl;

		Tile* currentTile = MouseHover();

		for (int i = 0; i < 4; i++)
		{
			if ((builders[i].x == currentTile->x) && (builders[i].y == currentTile->y))
			{
				if (player == builders[i].player) // If player owns builder
				{
					builderSelected = true;
					selectedBuilder = &builders[i];
					break;
				}
			}
		}

		if (builderSelected)
		{
			currentAction = PlayerState::Move;
		}
	}
}

void World::MovePlayer(int& player)
{
	bool playerMoved = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseClicked = false;
	}

	if ((!mouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		mouseClicked = true;

		std::cout << "MOVE" << std::endl;
		std::cout << playerTurn << std::endl;

		Tile* currentTile = MouseHover();

		selectedBuilder->Move(currentTile->x, currentTile->y);
		playerMoved = true;
	}

	if (playerMoved)
	{
		currentAction = PlayerState::Build;
	}
}

void World::BuildPlayer()
{
	bool playerBuilt = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseClicked = false;
	}

	if ((!mouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		mouseClicked = true;

		std::cout << "BUILD" << std::endl;
		std::cout << playerTurn << std::endl;

		Tile* currentTile = MouseHover();
	}

	if (playerBuilt)
	{
		turn++;
		currentAction = PlayerState::Select;
	}
}