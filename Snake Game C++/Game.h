#pragma once



#include "Player.h"
#include "Balls.h"
#include "Tail.h"
#include <sstream>
//This class is where most of the game calculaions are done and where the window is created. 


class Game
{
private:
	//variables controlling the window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	bool endGame;
	sf::Event sfmlEvent;

	//variables controlling the game
	Player player;

	Balls ball;

	std::vector<Tail> tails;

	void tailMovement();

	int playerscore;

	bool ballPresent;


	//Initializers
	void initWindow();
	void initVariables();
	void initPlayer();
	void initFont();
	void initText();


	//variables controlling the text
	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

public:
	//constructor/deconstructor
	Game();
	~Game();

	//Controls where the ball is placed
	void spawnBalls();

	//Determines if the game loop ends
	const bool running() const;

	//Accessors
	bool getEndGame();


	//Updates and renders the text
	void updateGUI();
	void renderGUI(sf::RenderTarget* target);
	void renderGameOver(sf::RenderTarget* target);

	//Updates and Renders the game
	void updatePlayer();
	void pollEvents();
	void update();
	void render();
};



