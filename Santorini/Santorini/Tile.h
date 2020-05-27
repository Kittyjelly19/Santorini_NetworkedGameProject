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

	unsigned short x;
	unsigned short y;

	
	//Set defualt tile outline. 
	bool isOutlined = false;
};

#endif