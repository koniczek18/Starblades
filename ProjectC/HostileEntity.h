#pragma once
#include "Entity.h"
class HostileEntity :public Entity
{
private:
	int ID;
	std::string name;
	int tier;
	std::vector<std::pair<std::string, int>> ability; // 0, 1, 2, 3, 4
	Entity* player;
	int lastPlayed = -1;
public:
	HostileEntity();
	~HostileEntity();

	void setID(int _ID);
	void setName(std::string _name);
	void setTier(int _tier);
	void setAbility(std::string,int _no, int _ability);

	void linkPlayer(Entity *_player);

	void play();
};

