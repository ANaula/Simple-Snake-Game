#include "Tail.h"

//Initializes tail part, setting the size,color, and position
void Tail::initShape(float x, float y)
{
	this->shape.setRadius(25.0f);
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setPosition(sf::Vector2f(x, y));
}

//Constructor/deconstructor
Tail::Tail(float x, float y)
{
	this->initShape(x, y);
}

Tail::~Tail()
{
}

//Accessor
sf::CircleShape& Tail::getshape()
{
	return shape;
}


//Renders tail object
void Tail::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}


