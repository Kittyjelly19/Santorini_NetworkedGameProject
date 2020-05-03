#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef TILE_HPP
#define TILE_HPP

class Tile : public Entity
{
private:

public:
	Tile();
	~Tile();

	void Draw(sf::RenderWindow& w);
	bool Build();

	unsigned short x;
	unsigned short y;

	unsigned short level = 0;

	bool hasOutline = false;
};

#endif