#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

#ifndef GAME_HPP
#define GAME_HPP
//#define MAX_NUM_PLAYERS 2

//enum for Game states
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
	//World instance and rendering.
	sf::RenderWindow window;
	World* world = NULL;

	
	

public:
	//Default Game state. 
	GameStates runningState = GameStates::SetUpGameState;
	void SetUpGame();
	void Play();
	Game();
	~Game();

	//Game
	void MainGameLoop();



};
#endif
