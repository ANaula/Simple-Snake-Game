#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//This class defines the ball that the player is supposed to touch to gain points

class Balls
{
private:

	//creates ball shape and initializes it 
	sf::CircleShape shape;

	void initShape();

public:
	//constructor/deconstructor
	Balls();
	~Balls();

	//Function used for repositioning ball
	void relocate(sf::RenderWindow& window);


	//Accessor
	sf::CircleShape& getShape();

	//Renders ball
	void render(sf::RenderTarget* target);
};



