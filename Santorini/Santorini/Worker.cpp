#include "Worker.h"
#include <iostream>

Worker::Worker(unsigned short x_, unsigned short y_, unsigned short p_) : x(x_), y(y_), playerID(p_)
{
}

Worker::~Worker()
{
}

void Worker::Draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(40, 40);
	sf::Color fColor = sf::Color::Blue;

	if (playerID == 1)
	{
		fColor = sf::Color::Red;
	}

	circle.setFillColor(fColor);
	circle.setPosition(x * 120 + 20, y * 120 + 20);

	window.draw(circle);
}

void Worker::MoveWorker(unsigned short i, unsigned short j)
{
	x = i;
	y = j;
}
