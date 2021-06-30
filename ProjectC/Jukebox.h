#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

#pragma once
class Jukebox
{
private:
	std::vector<sf::SoundBuffer> boom;
	sf::SoundBuffer laser;
	sf::SoundBuffer shields;
	sf::SoundBuffer victorySound;
	std::vector<sf::SoundBuffer> enemy; //0-fighter, 1- lancer, 2-ufo
	sf::SoundBuffer defeat;
	sf::SoundBuffer heal;

	sf::Sound soundBox;
public:
	Jukebox();
	~Jukebox();
	void init();
	void play(int id);

	/*if (id == 0)
	{
		soundBox.setBuffer(boom[0]);
	}
	if (id == 1)
	{
		soundBox.setBuffer(boom[1]);
	}
	if (id == 2)
	{
		soundBox.setBuffer(boom[2]);
	}
	if (id == 3)
	{
		soundBox.setBuffer(laser);
	}
	if (id == 4)
	{
		soundBox.setBuffer(shields);
	}
	if (id == 5)
	{
		soundBox.setBuffer(victorySound);
	}
	if (id == 6)
	{
		soundBox.setBuffer(enemy[0]);
	}
	if (id == 7)
	{
		soundBox.setBuffer(enemy[1]);
	}
	if (id == 8)
	{
		soundBox.setBuffer(enemy[2]);
	}
	if (id == 9)
	{
		soundBox.setBuffer(defeat);
	}
	if (id == 10)
	{
		soundBox.setBuffer(heal);
	}*/
};

