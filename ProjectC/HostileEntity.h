#pragma once
#include "Entity.h"
#include <iostream>
#include <sstream>
#include <string>

class HostileEntity :public Entity
{
private:
	int ID;
	std::string name;
	int tier;
	int ability[5] = { 0,0,0,0,0 }; //0-Dmg, 1-Heal HP, 2-Restore Shields, 3-Decrease enemy power, 4 - Increase sefl X
	int abilityDuoA[3] = { 0,0,0 }; //5 - Increase self X and dmg, 6 - Increase self X and heal Overall, 7 - Heal Overall and dmg
	int abilityDuoB[3] = { 0,0,0 };
	int lastPlayed = -1;
public:
	HostileEntity();
	~HostileEntity();

	void setID(int _ID);
	void setName(std::string _name);
	void setTier(int _tier);
	void setAbility(int _no, int _value);
	void setAbility(int _no, int _value1,int _value2);

	void play(sf::Text& tekst, Entity& player);
	void playEffect(int _code,sf::Text& tekst, Entity& player);

	int getTier();


};

