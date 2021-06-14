#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MainMenu.h"
#include "Gameplay.h"

#pragma once

class MainMenu;

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
	void end();
	void changeScene(std::string scene);
};

