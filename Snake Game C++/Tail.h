#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//This class defines the body/tail end of the snake. The body is represented by circles and 
//after each ball is consumed by the player, it increased in size by one circle shape. These
//circle shapes follow the player object.

class Tail
{
private:
	//Creates tail object and initializes it
	sf::CircleShape shape;
	void initShape(float x, float y);

public:

	//Constructor/deconstructor
	Tail(float x, float y);
	~Tail();

	//Accessor
	sf::CircleShape& getshape();


	//Renders tail
	void render(sf::RenderTarget* target);
};



