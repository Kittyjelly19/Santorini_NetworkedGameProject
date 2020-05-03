#include <SFML/Graphics.hpp>
#include "World.h"

#ifndef GAME_HPP
#define GAME_HPP

enum class GameState
{
	PlaceState,
	PlayState,
	WinState,
	LoseState,
	MenuState,
	Exit,
};

class Game
{
private:
	sf::RenderWindow window;
	World* world = NULL;

	//void Place();
	void Play();
	void Victory();
	void Defeat();

public:
	GameState state = GameState::PlayState;

	Game();
	~Game();

	void Run();
};
#endif
