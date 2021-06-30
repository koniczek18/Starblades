#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>

#include "Entity.h"
#include "Card.h"
#include "HostileEntity.h"

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
	sf::Text playerEnergy;
	sf::Text enemyEnergy;

	sf::Texture healthBar;
	sf::Texture shieldBar;
	sf::Texture statusBar;
	sf::Texture cardSlotTX;

	sf::Font font;

	bool playerTurn = true;
	Entity player;
	HostileEntity enemy;

	std::string currentGameplay = "Class selection";
	std::vector<sf::Text> classSelection;

	std::vector<Card> database;
	std::vector<HostileEntity> heDatabase;
	std::vector<Card > playerDeck;
	std::vector<Card> inGameCards;
	std::vector<Card> discardPile;

	int level;

public:

	Gameplay();
	~Gameplay();
	void render(sf::RenderWindow& window);
	void update(sf::Time& elapsed);
	void click(sf::Vector2f& pos, Game* game);

	void setBasePositions();
	void drawCards();
	void randomisePlayerDeck();
	void initCardbase();
	void initHeDatabase();

	void selectRandomEnemy(int tier);
};

