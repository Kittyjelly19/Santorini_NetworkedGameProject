#include "World.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>
//#include <algorithm>

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
	DrawHoverOutline();
	DrawGameBoard();
	
	for (int i = 0; i < numTiles; i++)
	{
		for (int j = 0; j < numTiles; j++)
		{
			boardTilesArr[i][j].x = i;
			boardTilesArr[i][j].y = j;

			boardTilesArr[i][j].buildLevel = 0;
		}
	}
	
	playerTurn = 0;
	PlaceWorker();
	
	
	
	//Making workers exist in game and adding to vector. 
	/*workers.push_back(Worker(1, 1, 0));
	workers.push_back(Worker(3, 3, 0));
	workers.push_back(Worker(3, 1, 1));
	workers.push_back(Worker(1, 3, 1));*/
	/*numPlayers = players;*/

	
}


//Drawing the game level. 
void World::DrawGameBoard()
{
	window.clear();

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boardTilesArr[i][j].DrawTile(window);
		}
	}

	//Drawing workers.
	/*for (int i = 0; i < 4; i++)
	{
		workers[i].Draw(window);
	}*/
}
void World::Update()
{
	DrawHoverOutline();

	//Player turn
	playerTurnID = playerTurn % numPlayers; 


	//Possible Player states.
	switch (currentPState)
	{
	case PlayerStates::PlaceWorkerState:
		PlaceWorker();
		break;
	
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





Tile* World::Hover()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	int A = 0;
	int B = 0;

	for (int a = 0; a < numTiles; a++)
	{
		for (int b = 0; b < numTiles; b++)
		{
			boardTilesArr[a][b].isOutlined = false;

			if (mousePos.x >= boardTilesArr[a][b].x * 120 + 5)
			{
				if (a < 4)
				{
					if (mousePos.x <= boardTilesArr[a + 1][b].x * 120 + 5)
					{
						A = a;
					}
				}
				else
				{
					A = a;
				}
			}

			if (mousePos.y >= boardTilesArr[a][b].y * 120 + 5)
			{
				if (b < 4)
				{
					if (mousePos.y <= boardTilesArr[a][b + 1].y * 120 + 5)
					{
						B = b;
					}
				}
				else
				{
					B = b;
				}
			}
		}
	}

	return &(boardTilesArr[A][B]);
}

void World::DrawHoverOutline()
{
	Tile* hoveredTile = Hover();
	hoveredTile->isOutlined = true;
}


void World::PlaceWorker()
{
	hasPlacedWorkers = false;

	playerTurnID = playerTurn % numPlayers;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (!sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

			Tile* hoveredTile = Hover();
	}
}


void World::SelectWorker(int& player)
{
	bool hasChosenWorker = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

		std::cout << "WORKER SELECTED" << std::endl;
		
		Tile* hoveredTile = Hover();

		for (int i = 0; i < 4; i++)
		{
			if ((workers[i].x == hoveredTile->x) && (workers[i].y == hoveredTile->y))
			{
				if (player == workers[i].playerID) 
				{
					hasChosenWorker = true;
					chosenWorker = &workers[i];
					break;
				}
			}
		}

		if (hasChosenWorker)
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

		Tile* currentTile = Hover();

		chosenWorker->MoveWorker(currentTile->x, currentTile->y);
		playerMoved = true;
	}

	if (playerMoved)
	{
		currentPState = PlayerStates::BuildState;
	}
}

void World::Build()
{
	bool hasBuiltOnTile = false;

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;

		std::cout << "BUILD" << std::endl;
		std::cout << playerTurnID << std::endl;

		Tile* hoveredTile = Hover();
	}

	if (hasBuiltOnTile)
	{
		playerTurn++;
		currentPState = PlayerStates::SelectWorkerState;
	}
}