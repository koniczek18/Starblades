#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

#pragma once
class MainMenu
{
private:
	sf::Text graj;
	sf::Text pomoc;
	sf::Text wyjscie;
	sf::Font font;
	sf::Sprite logo;

public:
	MainMenu();
	~MainMenu();

	void render(sf::RenderWindow& window);
};

