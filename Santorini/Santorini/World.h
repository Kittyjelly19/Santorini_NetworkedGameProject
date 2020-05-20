#include <SFML/Graphics.hpp>
#include <array>
#include "Tile.h"
#include "Worker.h"

#ifndef WORLD_HPP
#define WORLD_HPP

class Game;

//enum for possible player states
enum PlayerStates
{
	WaitForOpposition,
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
	std::array<std::array<Tile, 5>, 5> tiles{ {{{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}} };
	
	//Vector storing workers
	std::vector<Worker> workers;

	//Setting default player state and default selected worker.
	PlayerStates currentPState = PlayerStates::SelectWorkerState;
	Worker* selectedWorker = NULL;

	//Setting game defaults.
	int numPlayers = 2;

	unsigned short turn;

	int playerTurnID = 0;

	bool isMouseClicked = false;

public:
	
	World(sf::RenderWindow& w, Game* g);
	~World();

	void Setup();
	void Update();
	void Draw();

	Tile* MouseHover();
	void DrawHover();

	void SelectWorker(int& player);
	void MoveWorker(int& player);
	void Build();

	int boardTiles = 5;
};
#endif