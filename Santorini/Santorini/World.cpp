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
	for (int i = 0; i < boardTiles; i++)
	{
		for (int j = 0; j < boardTiles; j++)
		{
			tiles[i][j].x = i;
			tiles[i][j].y = j;

			tiles[i][j].level = 0;
		}
	}

	workers.push_back(Worker(1, 1, 0));
	workers.push_back(Worker(3, 3, 0));
	workers.push_back(Worker(3, 1, 1));
	workers.push_back(Worker(1, 3, 1));
	/*numPlayers = players;*/

	turn = 0;
}

void World::Update()
{
	DrawHover();


	playerTurnID = turn % 2; // Determines which players go it is

	switch (currentPState)
	{
	case PlayerStates::SelectWorkerState:
		SelectWorker(playerTurnID);
		break;

	case PlayerStates::MoveWorkerState:
		MoveWorker(playerTurnID);
		break;

	case PlayerStates::BuildState:
		Build();
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
			tiles[i][j].DrawTile(window);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		workers[i].Draw(window);
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
			tiles[i][j].isOutlined = false;

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
	currentTile->isOutlined = true;
}

void World::SelectWorker(int& player)
{
	bool isWorkerSelected = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

		std::cout << "WORKER SELECTED" << std::endl;
		
		Tile* currentTile = MouseHover();

		for (int i = 0; i < 4; i++)
		{
			if ((workers[i].x == currentTile->x) && (workers[i].y == currentTile->y))
			{
				if (player == workers[i].playerID) // If player owns builder
				{
					isWorkerSelected = true;
					selectedWorker = &workers[i];
					break;
				}
			}
		}

		if (isWorkerSelected)
		{
			currentPState = PlayerStates::MoveWorkerState;
		}
	}
}

void World::MoveWorker(int& player)
{
	bool playerMoved = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

		std::cout << "MOVE" << std::endl;
		std::cout << playerTurnID << std::endl;

		Tile* currentTile = MouseHover();

		selectedWorker->MoveWorker(currentTile->x, currentTile->y);
		playerMoved = true;
	}

	if (playerMoved)
	{
		currentPState = PlayerStates::BuildState;
	}
}

void World::Build()
{
	bool playerBuilt = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

		std::cout << "BUILD" << std::endl;
		std::cout << playerTurnID << std::endl;

		Tile* currentTile = MouseHover();
	}

	if (playerBuilt)
	{
		turn++;
		currentPState = PlayerStates::SelectWorkerState;
	}
}