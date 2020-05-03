#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef BUILDER_HPP
#define BUILDER_HPP

class Builder : public Entity
{
private:

public:
	Builder(unsigned short x, unsigned short y, unsigned short player);
	~Builder();

	unsigned short player;

	unsigned short x;
	unsigned short y;

	void Draw(sf::RenderWindow& window);
	void Move(unsigned short i, unsigned short j);
};

#endif
