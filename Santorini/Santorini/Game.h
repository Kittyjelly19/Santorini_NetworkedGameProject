#include <SFML/Graphics.hpp>
#include "World.h"

#ifndef GAME_HPP
#define GAME_HPP
#define MAX_NUM_PLAYERS 2

enum class GameStates
{
	MenuState,
	SetUpGameState,
	PlayState,
	ExitState
};


class Game
{
private:
	sf::RenderWindow window;
	World* world = NULL;

	void SetUpGame();
	void Play();
	

public:
	GameStates runningState = GameStates::SetUpGameState;

	Game();
	~Game();

	//Game
	void MainGameLoop();



};
#endif
