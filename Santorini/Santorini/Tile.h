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

	void DrawTile(sf::RenderWindow& w);
	bool BuildOnTile();

	unsigned short x;
	unsigned short y;

	unsigned short buildLevel = 0;

	bool isOutlined = false;
};

#endif