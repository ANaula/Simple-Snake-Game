#include "Game.h"

//Initializations
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1000, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Snake Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	ball.relocate(*this->window);

}

void Game::initVariables()
{
	this->endGame = false;
	this->ballPresent = true;

}
void Game::initPlayer()
{
	this->player.getShape().setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
}

void Game::initFont()
{
	this->font.loadFromFile("Fonts/Roboto-Bold.ttf");
}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(36);
	this->guiText.setPosition(sf::Vector2f(10.0f, 0.0f));

	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(38);
	this->endGameText.setPosition(sf::Vector2f(10.0f, this->window->getSize().y / 2));

}

//Functions that control text behavior
void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->playerscore;
	this->guiText.setString(ss.str());
}

void Game::renderGUI(sf::RenderTarget* target)
{

	target->draw(this->guiText);
}

void Game::renderGameOver(sf::RenderTarget* target)
{
	std::stringstream ss;
	ss << "Game over, you collected " << this->playerscore << " point(s). Press ESC to exit";
	this->endGameText.setString(ss.str());
	this->window->draw(this->endGameText);

}

//Function that controls the body of the snake
void Game::tailMovement()
{
	if (tails.size() > 0) {
		float prevX = tails[0].getshape().getGlobalBounds().left;
		float prevY = tails[0].getshape().getGlobalBounds().top;
		tails[0].getshape().setPosition(sf::Vector2f(this->player.getShape().getGlobalBounds().left, this->player.getShape().getGlobalBounds().top));
		float prev2X, prev2Y;

		for (int i = 1; i < tails.size(); i++) {
			prev2X = tails[i].getshape().getGlobalBounds().left;
			prev2Y = tails[i].getshape().getGlobalBounds().top;

			tails[i].getshape().setPosition(prevX, prevY);

			prevX = prev2X;
			prevY = prev2Y;

		}
	}



}

//Constructor/deconstructor
Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initPlayer();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

//Repoistions ball once it has been touched by player, increasing the player's score
void Game::spawnBalls()
{
	float prevx = this->player.getShape().getGlobalBounds().left;
	float prevy = this->player.getShape().getGlobalBounds().top;
	if (this->player.getShape().getGlobalBounds().intersects(this->ball.getShape().getGlobalBounds())) {
		this->ball.relocate(*this->window);
		this->tails.push_back(Tail(prevx, prevy));
		playerscore++;
	}

}

//Function that determines if the game is running based on if the window is open
const bool Game::running() const
{
	return this->window->isOpen();
}


//Returns endGame variable 
bool Game::getEndGame()
{
	return this->endGame;
}

//Functions that allows window to be closed either by pressing esc or clicking 'x' on the window
void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}
		}
	}
}

//Updates and renders different components of the game
void Game::updatePlayer()
{
	this->player.update(this->window);

	if (this->player.endGame == true) {
		this->endGame = true;
	}
}

void Game::update()
{
	this->pollEvents();
	if (this->endGame == false) {
		this->spawnBalls();
		this->tailMovement();
		this->updatePlayer();
		this->updateGUI();

	}


}

void Game::render()
{
	this->window->clear();

	this->player.render(this->window);

	this->ball.render(this->window);

	for (auto i : this->tails) {
		i.render(this->window);
	}

	this->renderGUI(this->window);

	if (this->endGame == true) {
		this->renderGameOver(this->window);
	}

	this->window->display();
}


