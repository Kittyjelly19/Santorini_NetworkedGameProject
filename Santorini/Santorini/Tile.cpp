#include "Tile.h"

Tile::Tile() : x(0), y(0), buildLevel(0)
{
}

Tile::~Tile()
{
}

void Tile::DrawTile(sf::RenderWindow& w)
{
	sf::RectangleShape tileRect;
	tileRect.setOutlineThickness(5);
	sf::Color tileOutline = sf::Color::Black;
	sf::Color tileColour = sf::Color::White;

	//if tile is empty
	if (buildLevel == 0) 
	{
		tileColour = sf::Color::Green;
		tileRect.setSize(sf::Vector2f(110, 110));
		tileRect.setPosition(x * 120 + 5, y * 120 + 5);
		tileRect.setFillColor(tileColour);

		if (isOutlined)
		{
			tileRect.setOutlineColor(sf::Color::Red);
		}

		w.draw(tileRect);
	}
	else
	{
		int maxBuildHeight = (buildLevel < 4) ? buildLevel : 3; // if (level < 4), true - limit == level, false - limit == 3

		for (int i = 0; i < maxBuildHeight; i++)
		{
			int size = 110 - (i * 20);
			tileRect.setSize(sf::Vector2f(size, size));
			tileRect.setPosition((x * 120) + (i * 10) + 5, (y * 120) + (i * 10) + 5);
			tileRect.setOutlineColor(tileOutline);
			tileRect.setFillColor(tileColour);
			w.draw(tileRect);
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
	/*std::cout << "Build on: " << x << " " << y << " " << buildLevel << std::endl;*/

	//increasing build height if less than maximum build height. 
	if (buildLevel < 4)
	{
		buildLevel++;
		return true;
	}

	return false;
}