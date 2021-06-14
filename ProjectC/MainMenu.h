#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

#include "BouncingStar.h"

#pragma once

class Game;


class MainMenu
{
private:
	sf::Text graj;
	sf::Text pomoc;
	sf::Text wyjscie;
	sf::Sprite logo;

	sf::Texture logoT;
	sf::Font lato;
	sf::Texture starT;

	std::vector<BouncingStar> stars;

public:
	MainMenu();
	~MainMenu();

	void render(sf::RenderWindow& window);
	void update(sf::Time& elapsed);
	void click(sf::Vector2f& pos,Game *game);

};

