#include "Builder.h"
#include <iostream>

Builder::Builder(unsigned short x_, unsigned short y_, unsigned short p_) : x(x_), y(y_), player(p_)
{
}

Builder::~Builder()
{
}

void Builder::Draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(40, 40);
	sf::Color fColor = sf::Color::Blue;

	if (player == 1)
	{
		fColor = sf::Color::Red;
	}

	circle.setFillColor(fColor);
	circle.setPosition(x * 120 + 20, y * 120 + 20);

	window.draw(circle);
}

void Builder::Move(unsigned short i, unsigned short j)
{
	x = i;
	y = j;
}
