#include <SFML/Graphics.hpp>

#ifndef ENTITY_HPP
#define ENTITY_HPP

//using namespace sf;
class Entity
{
private:

public:
	sf::Shape* shape;
	sf::Color color;

	sf::Vector2f GetPosition();
};

#endif