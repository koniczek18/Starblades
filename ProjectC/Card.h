#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

#include "Entity.h"

#pragma once

class Card:public sf::Sprite
{
private:
	int ID;

	float data[14];
	/*
	[0] dmgToTarget;
	[1] dmgToSelf;
	[2] sDmgToTarget;
	[3] sDmgToSelf;
	[4] hDmgToTarget;
	[5] hDmgToSelf;

	[6] healTarget;
	[7] healSelf;
	[8] restoreShieldsTarget;
	[9] restoreShieldsSelf;
	[10] restoreHealthTarget;
	[11] restoreHealthSelf;
	[12] modifyTargetEnergy
	[13] modifySelfEnergy
	*/

	sf::Texture tekstura;
	std::string status = "n/a"; // n/a, inHand, inDeck //

public:
	Card();
	~Card();

	void loadDataFromFile(std::string _path);
	void setData(std::vector<float> _data);
	void setData(int _id, float value);
	void setData(float _data[12]);

	void setTextureFromFile(std::string _path);

	void play(Entity &owner, Entity &target);
	void setPositionTo(int pos);

};

