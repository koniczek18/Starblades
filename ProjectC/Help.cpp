#include "Help.h"
#include "Game.h"

Help::Help()
{
	//Loading
	lato.loadFromFile("assets/font/Lato-Black.ttf");

	powrot.setFont(lato);
	powrot.setString("Powrót");
	powrot.setScale(1.0f, 1.0f);
	powrot.setPosition(1000, 600);
	powrot.setCharacterSize(30U);

}

Help::~Help()
{
}

void Help::render(sf::RenderWindow& window)
{
	window.draw(powrot);
}

void Help::update(sf::Time& elapsed)
{
}

void Help::click(sf::Vector2f& pos, Game* game)
{
	if (powrot.getGlobalBounds().contains(pos))
	{
		game->changeScene("Main menu");
	}
}
