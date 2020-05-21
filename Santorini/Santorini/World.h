#include <SFML/Graphics.hpp>
#include <array>
#include "Tile.h"
#include "Worker.h"

#ifndef WORLD_HPP
#define WORLD_HPP

class Game;

//enum for player states
enum PlayerStates
{

	PlaceWorkerState,
	SelectWorkerState,
	MoveWorkerState,
	BuildState,
};

class World
{
private:
	
	//Game instance and rendering.
	Game* g;
	sf::RenderWindow& window;

	
	//Array storing grid tiles.
	std::array<std::array<Tile, 5>, 5> boardTilesArr{ {{{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}} };
	
	
	//Setting default player state and default chosen worker.
	PlayerStates currentPState = PlayerStates::PlaceWorkerState;
	Worker* chosenWorker = NULL;
	Tile* hoveredTile = NULL;
	Tile* builderTile = NULL;

	
	//Vector storing workers
	std::vector<Worker> workers;
	
	//Setting player defaults.
	int numPlayers = 2;
	unsigned short playerTurn;
	int playerTurnID = 0;
	bool hasPlacedWorkers = false;

	

public:
	
	World(sf::RenderWindow& w, Game* g);
	~World();

	//Set up world
	void Setup();
	void Update();

	void DrawGameBoard();

	//Set up mouse
	bool isMouseClicked = false;
	Tile* Hover();
	void DrawHoverOutline();

	//Possible Player actions
	void PlaceWorker();
	void SelectWorker(int& player);
	void MoveWorker(int& player);
	void Build();
	bool areMaxWorkersPlaced() { return hasPlacedWorkers; };

	//Tile Checks
	bool isInRange = true;
	bool isOccupied = false;
	int numTiles = 5;
};
#endif