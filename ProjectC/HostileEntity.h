#pragma once
#include "Entity.h"
#include <iostream>
class HostileEntity :public Entity
{
private:
	int ID;
	std::string name;
	int tier;
	int ability[5] = { 0,0,0,0,0 }; //0-Dmg, 1-Heal HP, 2-Restore Shields, 3-Decrease enemy power, 4 - Increase sefl X
	std::pair<int, int> abilityDuo[3]; //5 - Increase self X and dmg, 6 - Increase self X and heal Overall, 7 - Heal Overall and dmg
	Entity* player;
	int lastPlayed = -1;
public:
	HostileEntity();
	~HostileEntity();

	void setID(int _ID);
	void setName(std::string _name);
	void setTier(int _tier);
	void setAbility(int _no, int _value);
	void setAbility(int _no, int _value1,int _value2);

	void linkPlayer(Entity *_player);

	void play();
	void playEffect(int _code);

	int getTier();


};

