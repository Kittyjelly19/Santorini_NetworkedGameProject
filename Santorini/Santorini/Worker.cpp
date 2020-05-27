#include "Worker.h"
#include <iostream>

Worker::Worker(unsigned short x_, unsigned short y_, unsigned short p_) : wx(x_), wy(y_), playerID(p_)
{
}

Worker::~Worker()
{
}

void Worker::Draw(sf::RenderWindow& window)
{
	//Worker base variables.
	sf::CircleShape circle(40, 40);
	sf::Color fColor = sf::Color::Cyan;

	//Setting the Colour of player 2.
	if (playerID == 1)
	{
		fColor = sf::Color::Yellow;
	}

	circle.setFillColor(fColor);
	
	//Setting position on the tile. 
	circle.setPosition(wx * 120 + 20, wy * 120 + 20);

	window.draw(circle);
}

void Worker::MoveWorker(unsigned short i, unsigned short j)
{
	wx = i;
	wy = j;
}
