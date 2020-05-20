#include "Tile.h"

Tile::Tile() : x(0), y(0), level(0)
{
}

Tile::~Tile()
{
}

void Tile::DrawTile(sf::RenderWindow& w)
{
	sf::RectangleShape rectangle;
	rectangle.setOutlineThickness(5);
	sf::Color cOutline = sf::Color::Black;
	sf::Color cFill = sf::Color::White;

	if (level == 0) // Nothing built
	{
		cFill = sf::Color::Green;
		rectangle.setSize(sf::Vector2f(110, 110));
		rectangle.setPosition(x * 120 + 5, y * 120 + 5);
		rectangle.setFillColor(cFill);

		if (isOutlined)
		{
			rectangle.setOutlineColor(sf::Color::Red);
		}

		w.draw(rectangle);
	}
	else
	{
		int limit = (level < 4) ? level : 3; // if (level < 4), true - limit == level, false - limit == 3

		for (int i = 0; i < limit; i++)
		{
			int size = 110 - (i * 20);
			rectangle.setSize(sf::Vector2f(size, size));
			rectangle.setPosition((x * 120) + (i * 10) + 5, (y * 120) + (i * 10) + 5);
			rectangle.setOutlineColor(cOutline);
			rectangle.setFillColor(cFill);
			w.draw(rectangle);
		}
	}

	if (level == 4)
	{
		sf::CircleShape circle(40);
		circle.setPosition(x * 120 + 20, y * 120 + 20);
		circle.setFillColor(sf::Color::Red);
		w.draw(circle);
	}
}

bool Tile::BuildOnTile()
{
	std::cout << "Build: " << x << " " << y << " " << level << std::endl;

	if (level < 4)
	{
		level++;
		return true;
	}

	return false;
}