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
	WinState,
	LoseState,
	GameOverState,
	ExitState
};


class Game
{
private:
	sf::RenderWindow window;
	World* world = NULL;



	//void Place();
	void Play();
	void Winner();
	void Loser();

public:
	GameStates runningState = GameStates::PlayState;

	Game();
	~Game();

	//Game
	void MainGameLoop();
	void Render();

	//Menu
	void Menu();

	//Set up game 
	void SetUpGame();
	void RunGame();
	void PlaceWorker();
};
#endif
