#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#pragma once

class Game;

class Help
{
private:
	sf::Text powrot;

	sf::Font lato;

public:
	Help();
	~Help();
	void render(sf::RenderWindow& window);
	void update(sf::Time& elapsed);
	void click(sf::Vector2f& pos, Game* game);
};

