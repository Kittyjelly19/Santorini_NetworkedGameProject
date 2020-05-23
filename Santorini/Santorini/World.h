#pragma once
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
	PlayerStates currentPState = SelectWorkerState;
	Worker* chosenWorker = NULL;
	Tile* hoveredTile = NULL;
	

	
	//Vector storing workers
	std::vector<Worker> workers;
	
	//Setting player defaults.
	int numPlayers = 2;
	unsigned int playerTurn;
	int playerTurnID = 0;
	bool hasPlacedWorker = false;
	bool isValidMove = true;

	

public:
	
	World(sf::RenderWindow& w, Game* g);
	~World();

	//Set up world
	void Setup();
	void Update();
	void DrawGameLevel();

	//Set up mouse
	bool isMouseClicked = false;
	Tile* Hover();
	void DrawHoverOutline();

	//Possible Player actions
	void PlaceWorker();
	void SelectWorker(int& player);
	void MoveWorker(int& player);
	void Build();
	bool areMaxWorkersPlaced = false;
	

	//Tile Checks
	bool isInRange();
	bool isOccupied();
	int numTiles = 5;
};
#endif