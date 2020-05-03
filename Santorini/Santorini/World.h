#include <SFML/Graphics.hpp>
#include <array>
#include "Tile.h"
#include "Builder.h"

#ifndef WORLD_HPP
#define WORLD_HPP

class Game;

enum PlayerState
{
	Select,
	Move,
	Build,
};

class World
{
private:
	Game* g;
	sf::RenderWindow& window;

	std::array<std::array<Tile, 5>, 5> tiles{ {{{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}, {{Tile(), Tile(), Tile()}}} }; // ??????
	std::vector<Builder> builders;

	PlayerState currentAction = PlayerState::Select;
	Builder* selectedBuilder = NULL;

	unsigned short turn;

	int playerTurn = 0;

	bool mouseClicked = false;

public:
	World(sf::RenderWindow& w, Game* g);
	~World();

	void Setup();
	void Update();
	void Draw();

	Tile* MouseHover();
	void DrawHover();

	void SelectPlayer(int& player);
	void MovePlayer(int& player);
	void BuildPlayer();

	int boardSize = 5;
};
#endif