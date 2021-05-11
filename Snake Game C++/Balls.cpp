#include "Balls.h"

//Initializer
void Balls::initShape()
{
	this->shape.setRadius(20.0);
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(3.0f);
}

//constructor/deconstructor
Balls::Balls()
{
	this->initShape();
}

Balls::~Balls()
{
}

// Function that takes the window size and uses that to calculate where to place the ball next (inside view on window)
void Balls::relocate(sf::RenderWindow& window)
{
	float x;
	float y;
	do {
		x = rand() % window.getSize().x - this->shape.getGlobalBounds().width;
		y = rand() % window.getSize().y - this->shape.getGlobalBounds().height;
	} while (x < 0 || y < 0);
	this->shape.setPosition(sf::Vector2f(x, y));

}

//Accessor
sf::CircleShape& Balls::getShape()
{
	return this->shape;
}

//Renders ball
void Balls::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
