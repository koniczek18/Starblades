#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

int main()
{
	Game game;

	while (game.isGameRunning())
	{
		game.update();
		game.render();
	}

	return 0;
}