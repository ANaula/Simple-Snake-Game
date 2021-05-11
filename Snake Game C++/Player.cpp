#include "Player.h"

//Directions that will be used to move the player object with a single input
enum DIR { STOP = 0, LEFT, UP, RIGHT, DOWN };
DIR dir;

//Initializes player object shape and speed
void Player::initVariables()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->movementSpeed = 10.0f;
	endGame = false;
	dir = STOP;

}


//constructor/deconstructor
Player::Player()
{

	this->initVariables();
}

Player::~Player()
{
}

//Returns private shape variable, used so that variable is accessible to other classes
sf::RectangleShape& Player::getShape()
{
	return this->shape;
}

//Functions that control movement
void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir = RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = DOWN;
	}

}

void Player::updateMovement()
{
	switch (dir) {
	case LEFT:
		this->shape.move(-this->movementSpeed, 0.0f);
		break;
	case RIGHT:
		this->shape.move(this->movementSpeed, 0.0f);
		break;
	case UP:
		this->shape.move(0.0f, -this->movementSpeed);
		break;
	case DOWN:
		this->shape.move(0.0f, this->movementSpeed);
		break;
	}

}

//Prevents player object from going outside the view of the window
void Player::updateWindowBoundsCollision(sf::RenderTarget* target)
{
	//left side
	if (this->shape.getGlobalBounds().left <= 0.0f) {
		this->shape.setPosition(0.0f, this->shape.getGlobalBounds().top);
		endGame = true;
	}
	//right side
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
		endGame = true;

	}
	//top
	if (this->shape.getGlobalBounds().top <= 0) {
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.0f);
		endGame = true;

	}
	//bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
		endGame = true;

	}
}

//Updates and Renders the player object
void Player::update(sf::RenderTarget* target)
{
	this->updateInput();
	this->updateMovement();
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
