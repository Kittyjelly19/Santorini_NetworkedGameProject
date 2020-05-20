#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef WORKER_HPP
#define WORKER_HPP

class Worker : public Entity
{
private:

public:
	Worker(unsigned short x, unsigned short y, unsigned short player);
	~Worker();

	unsigned short playerID;

	unsigned short x;
	unsigned short y;

	void Draw(sf::RenderWindow& window);
	void MoveWorker(unsigned short i, unsigned short j);
};

#endif
