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
	enemyEnergy.setPosition(1150, 95);
	enemyEnergy.setCharacterSize(30);
	enemyEnergy.setFillColor(sf::Color::Black);

	ActionText.setFont(font);
	ActionText.setCharacterSize(30);
	ActionText.setString("default");

	enemyName.setFont(font);
	enemyName.setCharacterSize(20);

	player.setPosition(100, 300);

	//jukebox.init();

	cosmos.loadFromFile("assets/textures/cosmos.jpg");
	cosmosS.setTexture(cosmos, true);
	cosmosS.setScale(1.3f, 1.3f);
	cosmosS.setPosition(0, 0);
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
	else if((currentGameplay=="Game")||(currentGameplay=="EnemyTurn"))
	{
		window.draw(cosmosS);
		window.draw(playerStatusBar);
		window.draw(playerHealthBar);
		window.draw(playerShieldBar);
		window.draw(enemyStatusBar);
		window.draw(enemyHealthBar);
		window.draw(enemyShieldBar);
		window.draw(playerEnergy);
		window.draw(enemyEnergy);
		window.draw(player);
		window.draw(enemy);
		for (int i = 0; i < inGameCards.size(); i++)
		{
			window.draw(inGameCards[i]);
		}
		if (ActionText.getString() != "default")
		{
			window.draw(ActionText);
		}
		//window.draw(cardSlot); to narazie nie
	}
	else if ((currentGameplay == "DoubleKill") || (currentGameplay == "Defeat"))
	{
		window.draw(ActionText);
	}
	if (currentGameplay == "Victory")
	{
		window.draw(ActionText);
		for (auto& r : rewardPile)
		{
			window.draw(r);
		}
	}
	if (currentGameplay == "VictoryGame2")
	{
		window.draw(cosmosS);
		window.draw(ActionText);
		window.draw(player);
	}

}

void Gameplay::update(sf::Time& elapsed)
{
	player.Animate();
	enemy.Animate();

	playerEnergy.setString(std::to_string(player.getX()));
	enemyEnergy.setString(std::to_string(enemy.getX()));
	
	playerHealthBar.setPosition((-343 + (player.getPercentageVaule(true) * 343)), 4);
	playerShieldBar.setPosition((-249 + (player.getPercentageVaule(false) * 249)), 47);

	enemyHealthBar.setPosition((1280 + 343 - (enemy.getPercentageVaule(true) * 343)), 4);
	enemyShieldBar.setPosition((1280 + 249 - (enemy.getPercentageVaule(false) * 249)), 47);
	if (currentGameplay == "EnemyTurn")
	{
		if (elapser.asSeconds() < 3)
		{
			elapser += elapsed;
		}
		else
		{
			enemy.play(ActionText,player);
			currentGameplay = "Game";
			drawCards();
			elapser = sf::Time::Zero;
		}
	}
	if ((ActionText.getString() != "default")&&(currentGameplay!="Victory2"))
	{
		ActionText.setPosition(640 - (0.5 * ActionText.getLocalBounds().width), 680);
	}
	if ((currentGameplay == "Game") && (player.returnAlive() == false))
	{
		if ((player.returnAlive() == false) && (enemy.returnAlive() == false))
		{
			ActionText.setString("To koniec twojej przygody, ale przynajmniej wrog tez polegl...");
			elapser += elapsed;
			if (elapsed.asSeconds() > 3)
			{
				currentGameplay = "DoubleKill";
				elapser = sf::Time::Zero;
			}

		}
		else if (player.returnAlive() == false)
		{
			ActionText.setString("To koniec twojej przygody...");
			elapser += elapsed;
			if (elapsed.asSeconds() > 3)
			{
				currentGameplay = "Defeat";
				elapser = sf::Time::Zero;
			}
		}
	}
	if ((currentGameplay == "Game") && (enemy.returnAlive() == false))
	{
		ActionText.setString("Wygrales! Pora dobrac karte... Oslony zostaly zregenerowane");
		player.repairShields();
		initialiseRewardPile(level);
		currentGameplay = "Victory";
	}
	if (currentGameplay == "VictoryGame")
	{
		ActionText.setPosition(640 - (0.5 * ActionText.getLocalBounds().width), 500);
		player.setPosition(640 - (0.5 * ActionText.getLocalBounds().width), 200);
		ActionText.setString("ZWYCIESTWO");
		currentGameplay = "VictoryGame2";
	}
	if ((currentGameplay == "Game") && (player.returnAlive() == true) && (ActionText.getString() != "default"))
	{
		if (elapser.asSeconds() < 4)
		{
			elapser+=elapsed;
		}
		else
		{
			ActionText.setString("default");
			elapser=sf::Time::Zero;
		}
	}
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
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -1)|| (database[i].gettier() == 0))
						{
							playerDeck.emplace_back(database[i]);
						}
					}
					player.FromFile("assets/textures/odyssey.png", false, 0, 0);
					randomisePlayerDeck();
					drawCards();
					level = 0;
					selectRandomEnemy(level);
					enemy.resetCurrentStats();
					currentGameplay = ("Game");
				}
				else if (i == 1)
				{
					player.setClass("Curiosity");
					currentGameplay = ("Game");
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -2) || (database[i].gettier() == 0))
						{
							playerDeck.emplace_back(database[i]);
						}
					}
					player.FromFile("assets/textures/curiosity.png", false, 0, 0);
					randomisePlayerDeck();
					drawCards();
					level = 0;
					selectRandomEnemy(level);
					enemy.resetCurrentStats();
					currentGameplay = ("Game");
					player.activateMovementAnimations();
				}
				else if (i == 2)
				{
					player.setClass("Rouge");
					currentGameplay = ("Game");
					for (int i = 0; i < database.size(); i++)
					{
						if ((database[i].gettier() == -3) || (database[i].gettier() == 0))
						{
							playerDeck.emplace_back(database[i]);
						}
					}
					player.FromFile("assets/textures/rouge.png", true, 32, 14);
					randomisePlayerDeck();
					drawCards();
					level = 0;
					selectRandomEnemy(level);
					enemy.resetCurrentStats();
					currentGameplay = ("Game");
				}
				else if (i == 3)
				{
					std::cout << "Po co to klikasz?" << std::endl << "Chesz to zepsuc???" << std::endl;
				}
			}
		}
	}
	else if (currentGameplay == "Game")
	{
		{
			int temp = -1;
			for (int i = 0; i < inGameCards.size(); i++)
			{
				if (inGameCards[i].getGlobalBounds().contains(pos))
				{
					inGameCards[i].play(player, enemy);
					int temp = inGameCards.size();
					for (int j = 0; j < temp; j++)
					{
						discardPile.emplace_back(inGameCards[j]);
					}
					inGameCards.clear();
					if (enemy.returnAlive() == true)
					{
						currentGameplay = "EnemyTurn";
					}
					temp = i;
				}
			}
			if (temp != -1)
			{
				std::vector<Card> tempo;
				for (int i = 0; i < inGameCards.size(); i++)
				{
					if (i != temp)
					{
						tempo.emplace_back(inGameCards[i]);
					}
				}
				inGameCards.clear();
				inGameCards = tempo;
				resetInGameCards();
			}
		}
	}
	else if (currentGameplay == "Victory")
	{
		for (int i = 0; i < rewardPile.size(); i++)
		{
			if (rewardPile[i].getGlobalBounds().contains(pos))
			{
				currentGameplay = "Game";
				playerDeck.emplace_back(rewardPile[i]);
				rewardPile.clear();
				for (int j = 0; j < inGameCards.size(); j++)
				{
					playerDeck.emplace_back(inGameCards[j]);
				}
				inGameCards.clear();
				randomisePlayerDeck();
				drawCards();
				level++;
				ActionText.setString("default");
				selectRandomEnemy(level);
				enemy.resetCurrentStats();
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
			inGameCards[inGameCards.size() - 1].changePosition(inGameCards.size());
		}
		else
		{
			playerDeck = discardPile;
			discardPile.clear();
			randomisePlayerDeck();
		}
	}
	for (int i = 0; i < 3; i++)
	{
		inGameCards[i].resetTexture();
	}
}

void Gameplay::randomisePlayerDeck()
{
	std::vector<Card> temp;
	std::vector<int> full;
	for (int i = 0; i < playerDeck.size(); i++)
	{
		full.emplace_back(0);
	}
	int tempi;
	while (temp.size() != playerDeck.size())
	{
		tempi = rand() % playerDeck.size();
		if (full[tempi] == 0)
		{
			temp.emplace_back(playerDeck[tempi]);
			full[tempi] = 1;
		}
	}
	playerDeck.clear();
	playerDeck = temp;
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
			std::getline(str, a, ',');
			if (a != "null")
			{
				card.setSoundID(std::stoi(a));
			}
			database.emplace_back(std::move(card));
		}
	}
	file.close();
}

void Gameplay::initHeDatabase()
{
	std::fstream file2("assets/enemy.csv", std::fstream::in);
	if (file2.is_open())
	{
		std::string line2;
		std::getline(file2, line2);
		while (std::getline(file2, line2))
		{
			std::stringstream str2(line2);
			HostileEntity enemy;
			std::string a;
			std::string b;
			std::string c;
			std::getline(str2, a, ',');
			enemy.setID(std::stoi(a));
			std::getline(str2, a, ',');
			enemy.setName(a);
			std::getline(str2, a, ',');
			enemy.setTier(std::stoi(a));
			for (int i = 0; i < 8; i++)
			{
				if (i < 5)
				{
					std::getline(str2, a, ',');
					enemy.setAbility(i, std::stoi(a));
				}
				else
				{
					std::getline(str2, a, ',');
					std::getline(str2, b, ',');
					enemy.setAbility(i-5, std::stoi(a), std::stoi(b));
				}
			}
			std::getline(str2, a, ',');
			std::getline(str2, b, ',');
			std::getline(str2, c, ',');
			enemy.setBaseStats(std::stoi(a), std::stoi(b), std::stoi(c));
			enemy.setMaxStats(std::stoi(a), std::stoi(b), std::stoi(c));
			std::getline(str2, a, ',');
			enemy.FromFile(a, false, 0, 0);
			heDatabase.emplace_back(enemy);
		}
	}
	file2.close();
}

void Gameplay::resetInGameCards()
{
	drawCards();
	for (int i = 0; i < inGameCards.size(); i++)
	{
		inGameCards[i].changePosition(i+1);
	}
}

void Gameplay::selectRandomEnemy(int tier)
{
	std::vector<HostileEntity> h;
	for (auto& he : heDatabase)
	{
		if (he.getTier() == tier)
		{
			h.emplace_back(he);
		}
	}
	if (h.size() > 0)
	{
		enemy = h[rand() % h.size()];
		enemy.setScale(-1.0f, 1.f);
		enemy.activateMovementAnimations();
		enemy.setPosition(1100, 300);
		enemy.rotate(270.0f);
	}
	else
	{
		currentGameplay = "VictoryGame";
	}
}

void Gameplay::initialiseRewardPile(int tier)
{
	int temp[3] = { -1,-1,-1 };
	while ((temp[0] == -1)|| (temp[1] == -1)|| (temp[2] == -1))
	{
		int randomise = rand() % database.size();
		if (database[randomise].gettier() > 0)
		{
			if (temp[0] == -1)
			{
				temp[0] = randomise;
			}
			else if (temp[0] != randomise)
			{
				if (temp[1] == -1)
				{
					temp[1] = randomise;
				}
				else if ((temp[0] != randomise) && (temp[1] != randomise))
				{
					temp[2] = randomise;
				}
			}
		}
	}
	rewardPile.emplace_back(database[temp[0]]);
	rewardPile.emplace_back(database[temp[1]]);
	rewardPile.emplace_back(database[temp[2]]);
	rewardPile[0].changePosition(1);
	rewardPile[1].changePosition(2);
	rewardPile[2].changePosition(3);
	rewardPile[0].resetTexture();
	rewardPile[1].resetTexture();
	rewardPile[2].resetTexture();
}

