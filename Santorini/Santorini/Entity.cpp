#include "Entity.h"
#include <iostream>

sf::Vector2f Entity::GetPosition()
{
	return shape->getPosition();
} 