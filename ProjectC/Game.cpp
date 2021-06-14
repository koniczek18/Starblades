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
		if (ev.type == sf::Event::Closed)
		{
			this->renderWindow->close();
		}
		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mouse_position = renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*renderWindow));
				if (gameState == "Main menu")
				{

					mainMenu.click(mouse_position,this);

				}
			}

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

void Game::end()
{
	this->renderWindow->close();
}

void Game::changeScene(std::string scene)
{
	this->gameState = scene;
}

