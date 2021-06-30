#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu()
{
	//Loading
	lato.loadFromFile("assets/font/Lato-Black.ttf");
	starT.loadFromFile("assets/textures/star.png");
	logoT.loadFromFile("assets/textures/logo.png");

	graj.setCharacterSize(30U);
	graj.setString("Graj");
	graj.setFont(lato);
	graj.setPosition(600, 370);
	graj.setScale(1.2f, 1.2f);
	pomoc.setCharacterSize(30U);
	pomoc.setString("Jak grac");
	pomoc.setFont(lato);
	pomoc.setPosition(570, 460);
	pomoc.setScale(1.2f, 1.2f);
	wyjscie.setCharacterSize(30U);
	wyjscie.setString("Wyjscie");
	wyjscie.setFont(lato);
	wyjscie.setPosition(570, 540);
	wyjscie.setScale(1.2f, 1.2f);
	logo.setTexture(logoT);
	logo.setScale(0.2f, 0.2f);
	logo.setPosition(450, 50);
	float a = 0.2f;
	for (int i = 0; i < 10; i++)
	{
		stars.emplace_back(BouncingStar(a, a));
		stars[i].setTexture(starT,true);
	}


}

MainMenu::~MainMenu()
{

}

void MainMenu::render(sf::RenderWindow& window)
{
	for (auto& st : stars)
	{
		window.draw(st);
	}
	window.draw(graj);
	//window.draw(pomoc);
	window.draw(wyjscie);
	window.draw(logo);
	

}

void MainMenu::update(sf::Time& elapsed)
{
	for (auto& st : stars)
	{
		st.animate(elapsed);
	}
}

void MainMenu::click(sf::Vector2f& pos,Game *game)
{
	if (wyjscie.getGlobalBounds().contains(pos))
	{
		game->end();
	}
	else if (graj.getGlobalBounds().contains(pos))
	{
		game->changeScene("Gameplay");
	}
	//else if (pomoc.getGlobalBounds().contains(pos))
	//{
	//	game->changeScene("Help");
	//}

}


