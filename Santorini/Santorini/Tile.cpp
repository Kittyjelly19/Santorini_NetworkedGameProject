#include "Tile.h"

Tile::Tile() : x(0), y(0)
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

	
	tileColour = sf::Color::Green;
	tileRect.setSize(sf::Vector2f(110, 110));
	tileRect.setPosition(x * 120 + 5, y * 120 + 5);
	tileRect.setFillColor(tileColour);

	
	if (isOutlined)
	{
		tileRect.setOutlineColor(sf::Color::Blue);
	}
		w.draw(tileRect);
		
}
