#include "MainMenu.h"

MainMenu::MainMenu()
{
	font.loadFromFile("Lato-Black.ttf");
	graj.setCharacterSize(30U);
	graj.setString("Graj");
	graj.setFont(font);
	graj.setPosition(350, 280);
	pomoc.setCharacterSize(30U);
	pomoc.setString("Jak grac");
	pomoc.setFont(font);
	pomoc.setPosition(330, 340);
	wyjscie.setCharacterSize(30U);
	wyjscie.setString("Wyjscie");
	wyjscie.setFont(font);
	wyjscie.setPosition(330, 410);

}

MainMenu::~MainMenu()
{

}

void MainMenu::render(sf::RenderWindow& window)
{
	window.draw(graj);
	window.draw(pomoc);
	window.draw(wyjscie);

}
