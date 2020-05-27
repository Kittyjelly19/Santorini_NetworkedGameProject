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

//Setting up board tiles and worker placement. 
void World::Setup()
{
	DrawHoverOutline();
	DrawGameLevel();
	
	numPlayers = 2;
	
	if (!areMaxWorkersPlaced)
	{
		currentPState = PlayerStates::PlaceWorker;
	}
	
}


//Drawing the game level. 
void World::DrawGameLevel()
{
	window.clear();
	//Drawing tiles.
	for (int x = 0; x < numTiles; x++)
	{
		for (int y = 0; y < numTiles; y++)
		{
			boardTilesArr[x][y].DrawTile(window);
		}
	}

	//Duplicating tiles. 
	for (int i = 0; i < numTiles; i++)
	{
		for (int j = 0; j < numTiles; j++)
		{
			boardTilesArr[i][j].x = i;
			boardTilesArr[i][j].y = j;

		}

	}
	//Drawing workers.
	for (int w = 0; w < workers.size(); w++)
	{
		workers[w].Draw(window);
	}
	
}

//Update function. 
void World::Update()
{
	DrawGameLevel();
	DrawHoverOutline();

	//Player turn
	playerTurnID = playerTurn % numPlayers; 


	//Possible Player states.
	switch (currentPState)
	{
	case PlayerStates::PlaceWorker:
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




//Mouse location to know where to draw hover outline. 
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

			// Hover along Width of the board.
			if (mousePosition.x >= boardTilesArr[a][b].x * 120 + 5)
			{
				if (a < 2)
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

			//Hover along length of the board.
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
	//Hover across whole board by multiplying length and width. 
	return &(boardTilesArr[A][B]);
}


void World::DrawHoverOutline()
{
	Tile* hoveredTile = Hover();
	hoveredTile->isOutlined = true;
}


void World::PlaceWorker()
{
	
	playerTurnID = playerTurn % numPlayers;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isMouseClicked = false;
	}

	if ((!isMouseClicked) && (!sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		isMouseClicked = true;
		std::cout << "Player " << playerTurnID << "has placed their worker" << std::endl;
		std::cout << "Next players turn" << std::endl;
			hoveredTile = Hover();
			//if the tile is not occupied, place a worker and add to the worker vector. 
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
			//When workers vector = max_num_workers (so 2 players = 4 workers)
			//set maximum workers placed. Used to break out of place worker state. 
			if (workers.size() == (MAX_NUM_WORKERS))
			{
				areMaxWorkersPlaced = true;
			}
			//Leave place state, move on to select worker state. 
			if (areMaxWorkersPlaced)
			{
				std::cout << "Maximum Workers Placed" << std::endl;
				currentPState = PlayerStates::SelectWorkerState;
			}
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

		
		
		hoveredTile = Hover();

		for (int w = 0; w < workers.size(); w++)
		{
			if ((workers[w].wx == hoveredTile->x) && (workers[w].wy == hoveredTile->y))
			{
				if (player == workers[w].playerID) 
				{
					std::cout << "Player " <<playerTurnID<< " has selected their worker!"<< std::endl;
					std::cout << "Player " << playerTurnID << " Choose a space to move to!" << std::endl;
					isValidMove = true;
					hasChosenWorker = true;
					chosenWorker = &workers[w];
					break;
				}
				else
				{
					std::cout << "That's Not your builder!" << std::endl;
					std::cout << "Player 0 = Blue" << std::endl;
					std::cout << "Player 1 = Yellow" << std::endl;
					isValidMove = false;
					
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
		std::cout <<"Player "<< playerTurnID <<" has moved their worker"<< std::endl;
		std::cout << "Player " << playerTurnID<< " Choose somewhere to build!"<<std::endl;
		

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
		
		std::cout << "Player " << playerTurnID << " is done building!" << std::endl;
		std::cout << "Next players turn" << std::endl;
		
		playerTurn++;
		hoveredTile = Hover();
		currentPState = PlayerStates::SelectWorkerState;
	}

	if (hasBuiltOnTile)
	{
		
		
	}
}

//Check if tile is in range of the selected builder.
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

//Check if tile is occupied. 
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
