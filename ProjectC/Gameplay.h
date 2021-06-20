#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include "Entity.h"

#pragma once

class Game;

class Gameplay
{
private:
	sf::Sprite playerHealthBar;
	sf::Sprite enemyHealthBar;
	sf::Sprite playerShieldBar;
	sf::Sprite enemyShieldBar;
	sf::Sprite playerStatusBar;
	sf::Sprite enemyStatusBar;
	sf::Sprite cardSlot;

	sf::Texture healthBar;
	sf::Texture shieldBar;
	sf::Texture statusBar;
	sf::Texture cardSlotTX;

	sf::Font font;

	bool playerTurn = true;
	Entity player;
	Entity enemy;

	std::string currentGameplay = "Class selection";
	std::vector<sf::Text> classSelection;

public:
	Gameplay();
	~Gameplay();
	void render(sf::RenderWindow& window);
	void update(sf::Time& elapsed);
	void click(sf::Vector2f& pos, Game* game);

	void setBasePositions();
	void gameplayInit();
};

