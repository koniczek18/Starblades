#include "HostileEntity.h"

HostileEntity::HostileEntity()
{
	ID = 0;
	name = "Default";
	tier = 0;
	for (int i = 0; i < 5; i++)
	{
		ability.emplace_back(std::make_pair("Default", 0));
	}
}

HostileEntity::~HostileEntity()
{
}

void HostileEntity::setID(int _ID)
{
	ID = _ID;
}

void HostileEntity::setName(std::string _name)
{
	name = _name;
}

void HostileEntity::setTier(int _tier)
{
	tier = _tier;
}

void HostileEntity::setAbility(std::string _name, int _no, int _ability)
{
	ability[_no].first = _name;
	ability[_no].second = _ability;
}

void HostileEntity::linkPlayer(Entity *_player)
{
	player = _player;
}

void HostileEntity::play()
{
	std::vector<std::pair<std::string, int>> abilities = ability;
	if (lastPlayed == -1)
	{
		while (abilities.size() > 3)
		{
			int nr = rand() % abilities.size();
			abilities.erase(abilities.begin() + nr - 1);
		}
	}
	else
	{
		abilities.erase(abilities.begin() + lastPlayed - 1);
		int nr = rand() % abilities.size();
		abilities.erase(abilities.begin() + nr - 1);
	}

}
