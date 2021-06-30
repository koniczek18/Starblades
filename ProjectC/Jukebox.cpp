#include "Jukebox.h"

Jukebox::Jukebox()
{
}

Jukebox::~Jukebox()
{
}

void Jukebox::init()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("assets/sound/boom0.wav");
	boom.emplace_back(buffer);
	buffer.loadFromFile("assets/sound/boom1.wav");
	boom.emplace_back(buffer);
	buffer.loadFromFile("assets/sound/boom2.wav");
	boom.emplace_back(buffer);

	laser.loadFromFile("assets/sound/laser.wav");
	shields.loadFromFile("assets / sound / shields.wav");

	buffer.loadFromFile("assets/sound/fighter.wav");
	enemy.emplace_back(buffer);
	buffer.loadFromFile("assets/sound/lancer.wav");
	enemy.emplace_back(buffer);
	buffer.loadFromFile("assets/sound/ufo.wav");
	enemy.emplace_back(buffer);

	defeat.loadFromFile("assets/sound/defeat.wav");
	heal.loadFromFile("assets/sound/heal.wav");
	victorySound.loadFromFile("assets/sound/victorysound.wav");

}

void Jukebox::play(int id)
{
	if (id == 0)
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
	}
	soundBox.play();
}
