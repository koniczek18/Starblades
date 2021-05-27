#include "WindowState.h"

void WindowState::VarInit()
{
	std::cout << "VarInit() started..." << std::endl;
	this->window = nullptr;
	this->game = new Game;
	this->player = new Unit;
	this->enemy = new Unit;
	std::cout << "VarInit() finished..." << std::endl;
}

void WindowState::InitWind()
{
	std::cout << "InitWind() started..." << std::endl;
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Project C", sf::Style::Titlebar | sf::Style::Close);
	std::cout << "InitWind() finished..." << std::endl;
}

WindowState::WindowState()
{
	std::cout << "Window creation..." << std::endl;
	this->VarInit();
	this->InitWind();
}

WindowState::~WindowState()
{
	delete this->window;
	std::cout << "Window deleted..." << std::endl;
	delete this->game;
	std::cout << "Game class deleted..." << std::endl;
	delete this->player;
	std::cout << "Player (unit class) deleted..." << std::endl;
	delete this->enemy;
	std::cout << "Enemy (unit class) deleted..." << std::endl;
}

const bool WindowState::isWindowOpen()
{
	return this->window->isOpen();
}

void WindowState::update()
{
	this->updateEv();
}

void WindowState::updateEv()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if(this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}

void WindowState::render()
{
	//Clear
	this->window->clear(sf::Color::Black);

	//Draw


	//Final display
	this->window->display();
}
