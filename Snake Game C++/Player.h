#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/Color.hpp>

//This class is for defining the player controlled object in the game

class Player
{
private:
	//Creates Player object and defines their speed
	sf::RectangleShape shape;

	float movementSpeed;

	//Initializers
	void initVariables();
public:
	//constructor/deconstructors
	Player();
	~Player();

	//Accessors
	sf::RectangleShape& getShape();

	//End game variable
	bool endGame;


	//Updates and Renders player object
	void updateInput();
	void updateMovement();
	void updateWindowBoundsCollision(sf::RenderTarget* target);

	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};



