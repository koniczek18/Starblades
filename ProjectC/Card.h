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
	std::string name;
	int data[14];
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
	int tier = 1;
	int position = 0;
	std::string path;

public:
	Card();
	~Card();

	void loadDataFromFile(std::string _path);
	void setData(std::vector<int> _data);
	void setData(int _id, int value);
	void setData(int _data[12]);
	void setID(int _id);
	void setName(std::string);
	void settier(int a);

	void setTextureFromFile(std::string _path);

	void play(Entity &owner, Entity &target);
	void setPositionTo(int pos);

	int getID();
	std::string getName();
	int getData(int a);
	sf::Texture returnTexture();
	int gettier();
	std::string returnPath();

	void operator=(Card& kard);
	void resetTexture();

	void changePosition(int i);

};

