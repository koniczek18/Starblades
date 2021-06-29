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
		for (int i = 0; i < inGameCards.size(); i++)
		{
			//inGameCards[i].resetTexture();
			window.draw(inGameCards[i]);
		}
		//window.draw(cardSlot); to narazie nie
	}

}

void Gameplay::update(sf::Time& elapsed)
{
	playerEnergy.setString(std::to_string(player.getPower()));
	enemyEnergy.setString(std::to_string(enemy.getPower()));
	float newX = (-343 + (player.getPercentageVaule(true) * 343));
	std::cout << newX << std::endl;
	playerHealthBar.setPosition(newX, 4);
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
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -1)|| (database[i].gettier() == 0))
						{
							playerDeck.emplace_back(database[i]);
						}
					}
					randomisePlayerDeck();
					drawCards();
				}
				else if (i == 1)
				{
					player.setClass("Curiosity");
					currentGameplay = ("Game");
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -2) || (database[i].gettier() == 0))
						{
							
						}
					}
					randomisePlayerDeck();
					drawCards();
				}
				else if (i == 2)
				{
					player.setClass("Rouge");
					currentGameplay = ("Game");
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -3) || (database[i].gettier() == 0))
						{
							
						}
					}
					randomisePlayerDeck();
					drawCards();
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

void Gameplay::drawCards()
{
	while (inGameCards.size() < 3)
	{
		if (playerDeck.size() > 0)
		{
			inGameCards.emplace_back(playerDeck[playerDeck.size() - 1]);
			playerDeck.pop_back();
			inGameCards[inGameCards.size() - 1].setPositionTo(inGameCards.size());
		}
		else
		{
			
		}
	}
	for (int i = 0; i < 3; i++)
	{
		inGameCards[i].resetTexture();
	}
}

void Gameplay::randomisePlayerDeck()
{

}

void Gameplay::initCardbase()
{
	std::fstream file("assets/gameplay.csv", std::fstream::in);
	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream str(line);
			Card card;
			std::string a;
			std::getline(str, a, ',');
			card.setID(std::stoi(a));
			std::getline(str, a, ',');
			card.setName(a);
			for (int i = 0; i < 14; i++)
			{
				std::getline(str, a, ',');
				card.setData(i, std::stoi(a));
			}
			std::getline(str, a, ',');
			card.settier(std::stoi(a));
			std::getline(str, a, ',');
			card.setTextureFromFile(a);
			database.emplace_back(std::move(card));
		}
	}
}

void Gameplay::initHeDatabase()
{
	std::fstream file("assets/enemy.csv", std::fstream::in);
	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream str(line);
			HostileEntity enemy;
			std::string a;
			std::getline(str, a, ',');
			enemy.setID(std::stoi(a));
			std::getline(str, a, ',');
			enemy.setName(a);
			std::getline(str, a, ',');
			enemy.setTier(std::stoi(a));
			for (int i = 0; i < 5; i++)
			{
				std::getline(str, a, ',');
				enemy.setAbility(i, std::stoi(a));
			}
			for (int i = 0; i < 3; i++)
			{
				std::getline(str, a, ',');
				std::string b = a;
				std::getline(str, a, ',');
				enemy.setAbility(i, std::stoi(b), std::stoi(a));
			}
			std::getline(str, a, ',');
			std::string c = a;
			std::getline(str, a, ',');
			std::string b = a;
			std::getline(str, a, ',');
			enemy.setBaseStats(std::stoi(c), std::stoi(b), std::stoi(a));
		}
	}
}