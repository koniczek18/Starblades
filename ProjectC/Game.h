#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MainMenu.h"

#pragma once

class Game
{
private:

	sf::RenderWindow* renderWindow;
	std::string gameState="Main menu";
	MainMenu mainMenu;
	sf::Event ev;


public:

	Game();
	~Game();

	bool isGameRunning();


	void update(sf::Time& elapsed);
	void updateEvents();
	void render();
};

