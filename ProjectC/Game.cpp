#include "Game.h"

Game::Game()
{
	this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Starblades", sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game()
{
	delete this->renderWindow;
}

bool Game::isGameRunning()
{
	return this->renderWindow->isOpen();
}

void Game::update()
{
	this->updateEvents();
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
