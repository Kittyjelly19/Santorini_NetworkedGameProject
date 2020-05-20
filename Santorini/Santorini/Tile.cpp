#include "Tile.h"

Tile::Tile() : x(0), y(0), buildLevel(0)
{
}

Tile::~Tile()
{
}

void Tile::DrawTile(sf::RenderWindow& w)
{
	sf::RectangleShape tileRectangle;
	tileRectangle.setOutlineThickness(5);
	sf::Color outlineColour = sf::Color::Black;
	sf::Color fillColour = sf::Color::White;

	//if tile is empty
	if (buildLevel == 0) 
	{
		fillColour = sf::Color::Green;
		tileRectangle.setSize(sf::Vector2f(110, 110));
		tileRectangle.setPosition(x * 120 + 5, y * 120 + 5);
		tileRectangle.setFillColor(fillColour);

		if (isOutlined)
		{
			tileRectangle.setOutlineColor(sf::Color::Red);
		}

		w.draw(tileRectangle);
	}
	else
	{
		int maxBuildHeight = (buildLevel < 4) ? buildLevel : 3; // if (level < 4), true - limit == level, false - limit == 3

		for (int i = 0; i < maxBuildHeight; i++)
		{
			int size = 110 - (i * 20);
			tileRectangle.setSize(sf::Vector2f(size, size));
			tileRectangle.setPosition((x * 120) + (i * 10) + 5, (y * 120) + (i * 10) + 5);
			tileRectangle.setOutlineColor(outlineColour);
			tileRectangle.setFillColor(fillColour);
			w.draw(tileRectangle);
		}
	}

	//If tile is at max build height 
	if (buildLevel == 4)
	{
		sf::CircleShape circle(40);
		circle.setPosition(x * 120 + 20, y * 120 + 20);
		circle.setFillColor(sf::Color::Red);
		w.draw(circle);
	}
}

bool Tile::BuildOnTile()
{
	std::cout << "Build on: " << x << " " << y << " " << buildLevel << std::endl;

	//increasing build height if less than maximum build height. 
	if (buildLevel < 4)
	{
		buildLevel++;
		return true;
	}

	return false;
}