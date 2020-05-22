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
	DrawHoverOutline();
	
	
	bool isBoardDrawn = false;
	
	DrawGameBoard();
	{
		for (int i = 0; i < numTiles; i++)
		{
			for (int j = 0; j < numTiles; j++)
			{
				boardTilesArr[i][j].x = i;
				boardTilesArr[i][j].y = j;

				boardTilesArr[i][j].buildLevel = 0;
			}
			
		}
		isBoardDrawn = true;
			{
				PlaceWorker();
			}

	}
	
	
	/*playerTurn = 0;*/
	/*PlaceWorker();*/
	
	
	
	

	
}


//Drawing the game level. 
void World::DrawGameBoard()
{
	window.clear();

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			boardTilesArr[x][y].DrawTile(window);
		}
	}

	for (int w = 0; w < workers.size(); w++)
	{
		workers[w].Draw(window);
	}
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
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	int A = 0;
	int B = 0;

	for (int a = 0; a < numTiles; a++)
	{
		for (int b = 0; b < numTiles; b++)
		{
			boardTilesArr[a][b].isOutlined = false;

			if (mousePosition.x >= boardTilesArr[a][b].x * 120 + 5)
			{
				if (a < 4)
				{
					if (mousePosition.x <= boardTilesArr[a + 1][b].x * 120 + 5)
					{
						A = a;
					}
				}
				else
				{
					A = a;
				}
			}

			if (mousePosition.y >= boardTilesArr[a][b].y * 120 + 5)
			{
				if (b < 4)
				{
					if (mousePosition.y <= boardTilesArr[a][b + 1].y * 120 + 5)
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

			hoveredTile = Hover();
			if (!isOccupied())
			{
				workers.push_back(Worker(hoveredTile->x, hoveredTile->y, playerTurnID));
				playerTurn++;
					
				isValidMove = true;
			}
			else
			{
				isValidMove = false;
			}
	}
	if (workers.size() == (numPlayers * 2))
	{
		/*hasPlacedWorkers = true;*/
		/*bool areMaxWorkersPlaced = true;*/
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
		
		hoveredTile = Hover();

		for (int i = 0; i < 4; i++)
		{
			if ((workers[i].wx == hoveredTile->x) && (workers[i].wy == hoveredTile->y))
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

		hoveredTile = Hover();

		chosenWorker->MoveWorker(hoveredTile->x, hoveredTile->y);
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

		hoveredTile = Hover();
	}

	if (hasBuiltOnTile)
	{
		playerTurn++;
		currentPState = PlayerStates::SelectWorkerState;
	}
}

bool World::isInRange()
{
	for (int xTiles = -1; xTiles < 2; xTiles++)
	{
		if (hoveredTile-> x == chosenWorker-> wx + xTiles)
		{
			for (int yTiles = -1; yTiles < 1; yTiles++)
			{
				if (hoveredTile->y == chosenWorker->wy + yTiles)
				{
					if (isOccupied())
					{
						return false;
					}
					return true;
				}
			}
		}
	}
}

bool World::isOccupied()
{
	for (int w = 0; w < workers.size(); w++)
	{
		if ((hoveredTile->x == workers[w].wx) && (hoveredTile->y == workers[w].wy))
		{
			return true;
		}
	}
	return false;
}
