#include "Gameplay.h"
#include "Game.h"

Gameplay::Gameplay()
{
	healthBar.loadFromFile("assets/textures/healthbar.png");
	shieldBar.loadFromFile("assets/textures/shieldbar.png");
	statusBar.loadFromFile("assets/textures/statusbar.png");
	cardSlotTX.loadFromFile("assets/textures/cardslot.png");
	font.loadFromFile("assets/font/Lato-Black.ttf");

	playerHealthBar.setTexture(healthBar);
	playerShieldBar.setTexture(shieldBar);
	playerStatusBar.setTexture(statusBar);
	enemyHealthBar.setTexture(healthBar);
	enemyShieldBar.setTexture(shieldBar);
	enemyStatusBar.setTexture(statusBar);
	cardSlot.setTexture(cardSlotTX);

	enemyHealthBar.setScale(-1.f, 1.f);
	enemyShieldBar.setScale(-1.f, 1.f);
	enemyStatusBar.setScale(-1.f, 1.f);

	setBasePositions();
	cardSlot.setPosition(0, 427);

	sf::Text odyssey;
	sf::Text curiosity;
	sf::Text rouge;
	sf::Text wybor;
	odyssey.setString("Odyssey");
	curiosity.setString("Curiosity");
	rouge.setString("Rouge");
	classSelection.emplace_back(odyssey);
	classSelection.emplace_back(curiosity);
	classSelection.emplace_back(rouge);
	wybor.setString("Wybierz klase");
	wybor.setPosition(525, 300);
	wybor.setFont(font);
	for (int i = 0; i < classSelection.size(); i++)
	{
		classSelection[i].setCharacterSize(25);
		classSelection[i].setPosition(400 + (i * 180), 400);
		classSelection[i].setFont(font);
	}
	classSelection.emplace_back(wybor);

	playerEnergy.setFont(font);
	playerEnergy.setPosition(5, 95);
	playerEnergy.setCharacterSize(30);
	playerEnergy.setFillColor(sf::Color::Black);
	enemyEnergy.setFont(font);
	enemyEnergy.setPosition(1250, 95);
	enemyEnergy.setCharacterSize(30);
	enemyEnergy.setFillColor(sf::Color::Red);

}

Gameplay::~Gameplay()
{

}

void Gameplay::render(sf::RenderWindow& window)
{
	if (currentGameplay == "Class selection")
	{
		for (auto& w : classSelection)
		{
			window.draw(w);
		}
	}
	else
	{
		window.draw(playerStatusBar);
		window.draw(playerHealthBar);
		window.draw(playerShieldBar);
		window.draw(enemyStatusBar);
		window.draw(enemyHealthBar);
		window.draw(enemyShieldBar);
		window.draw(playerEnergy);
		window.draw(enemyEnergy);
		for (auto& w : inGameCards)
		{
			window.draw(w);
		}
		//window.draw(cardSlot); to narazie nie
	}

}

void Gameplay::update(sf::Time& elapsed)
{
	playerEnergy.setString(std::to_string(player.getPower()));
	enemyEnergy.setString(std::to_string(enemy.getPower()));
	playerHealthBar.setPosition(-343 + (player.getPercentageVaule(true) * 343), 4);
}

void Gameplay::click(sf::Vector2f& pos, Game* game)
{
	if (currentGameplay == "Class selection")
	{
		for (int i = 0; i < classSelection.size(); i++)
		{
			if (classSelection[i].getGlobalBounds().contains(pos))
			{
				if (i == 0)
				{
					player.setClass("Odyssey");
					currentGameplay=("Game");
					for (int i = 0; i < 3; i++)
					{
						Card card;
						card.setTextureFromFile("assets/textures/card.png");
						inGameCards.emplace_back(card);
					}
					for (int i=0;i< inGameCards.size();i++)
					{
						inGameCards[i].setPositionTo(i);
						for (int j = 0; j < 14; j++)
						{
							inGameCards[i].setData(j, 10);
							inGameCards[i].setTextureFromFile("assets/textures/card.png");
						}
					}
					
				}
				else if (i == 1)
				{
					player.setClass("Curiosity");
					currentGameplay = ("Game");
				}
				else if (i == 2)
				{
					player.setClass("Rouge");
					currentGameplay = ("Game");
				}
				else if (i == 3)
				{
					std::cout << "Po co to klikasz?" << std::endl << "Chesz to zepsuc???" << std::endl;
				}
			}
		}
	}
	if (currentGameplay == "Game")
	{
		for (int i = 0; i < inGameCards.size(); i++)
		{
			if (inGameCards[i].getGlobalBounds().contains(pos))
			{
				inGameCards[i].play(player,enemy);
			}
		}
	}
}

void Gameplay::setBasePositions()
{
	playerStatusBar.setPosition(0, 0);
	playerHealthBar.setPosition(0, 4);
	playerShieldBar.setPosition(0, 47);

	enemyStatusBar.setPosition(1280, 0);
	enemyHealthBar.setPosition(1280, 4);
	enemyShieldBar.setPosition(1280, 47);
}

void Gameplay::gameplayInit()
{
	
}
