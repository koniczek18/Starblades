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
//#include "Jukebox.h"

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
	sf::Text enemyName;

	sf::Texture healthBar;
	sf::Texture shieldBar;
	sf::Texture statusBar;
	sf::Texture cardSlotTX;
	sf::Texture cosmos;
	sf::Sprite cosmosS;

	sf::Font font;

	Entity player;
	HostileEntity enemy;
	sf::Text ActionText;

	std::string currentGameplay = "Class selection";
	std::vector<sf::Text> classSelection;

	std::vector<Card> database;
	std::vector<HostileEntity> heDatabase;
	std::vector<Card > playerDeck;
	std::vector<Card> inGameCards;
	std::vector<Card> discardPile;
	std::vector<Card> rewardPile;

	int level;
	sf::Time elapser;

	//Jukebox jukebox;

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
	void resetInGameCards();

	void selectRandomEnemy(int tier);
	void initialiseRewardPile(int tier);
};

