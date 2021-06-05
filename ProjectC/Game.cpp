#include "Game.h"

Game::Game()
{
	this->renderWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Starblades", sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game()
{
	delete this->renderWindow;
}

bool Game::isGameRunning()
{
	return this->renderWindow->isOpen();
}

void Game::update(sf::Time& elapsed)
{
	this->updateEvents();
	if (gameState == "Main menu")
	{
		mainMenu.update(elapsed);
	}
}

void Game::updateEvents()
{
	while (this->renderWindow->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->renderWindow->close();
		}
	}
}

void Game::render()
{
	//
	this->renderWindow->clear(sf::Color::Black);
	//

	if (gameState == "Main menu")
	{
		mainMenu.render(*renderWindow);
	}

	//
	this->renderWindow->display();
	//
}

