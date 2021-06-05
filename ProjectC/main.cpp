#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

int main()
{
	Game game;
	sf::Time elapsed;
	sf::Clock clock;
	while (game.isGameRunning())
	{
		elapsed = clock.restart();
		game.update(elapsed);
		game.render();
	}

	return 0;
}