#include "HostileEntity.h"

HostileEntity::HostileEntity()
{
	ID = 0;
	name = "Default";
	tier = 0;
	for (int i = 0; i < 3; i++)
	{
		abilityDuo[i] = std::make_pair(0, 0);
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

void HostileEntity::setAbility(int _no,int _value)
{
	if ((_no >= 0) && (_no <= 4))
	{
		ability[_no] = _value;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
}

void HostileEntity::setAbility(int _no, int _value1, int _value2)
{
	if ((_no >= 5) && (_no <= 7))
	{
		abilityDuo[_no] = std::make_pair(_value1, _value2);
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
}

void HostileEntity::linkPlayer(Entity *_player)
{
	player = _player;
}

void HostileEntity::play()
{
	std::vector<int> abilityID;
	for (int i = 0; i < 8; i++)
	{
		if (i != lastPlayed)
		{
			if (i < 5)
			{
				if (ability[i] != 0)
				{
					abilityID.emplace_back(i);
				}
			}
			else
			{
				if (abilityDuo[i - 5] != std::make_pair(0, 0))
				{
					abilityID.emplace_back(i);
				}
			}
		}
	}
	if (abilityID.size() > 3)
	{
		while (abilityID.size() > 3)
		{
			abilityID.erase(abilityID.begin() + rand() % abilityID.size());
		}
	}
	int playCode = (rand() % abilityID.size());
	lastPlayed = playCode;
	playEffect(playCode);



}

void HostileEntity::playEffect(int _code)
{
	if (_code == 0)
	{
		float a = ability[0] * this->getX();
		int b = (int)a;
		player->receiveDamage(b);
	}
	else if (_code == 1)
	{
		this->restoreHealth(ability[1]);
	}
	else if (_code == 2)
	{
		this->restoreShields(ability[2]);
	}
	else if (_code == 3)
	{
		player->reduceX(ability[3] / 100);
	}
	else if (_code == 4)
	{
		this->addX(ability[4] / 100);
	}
	else if (_code == 5)
	{
		this->addX(abilityDuo[0].first / 100);
		float a = abilityDuo[0].second * this->getX();
		int b = (int)a;
		player->receiveDamage(b);
	}
	else if (_code == 6)
	{
		this->addX(abilityDuo[1].first / 100);
		this->restoreHealthAndShields(abilityDuo[1].second);
	}
	else if (_code == 7)
	{
		float a = abilityDuo[2].second * this->getX();
		int b = (int)a;
		player->receiveDamage(b);
		this->restoreHealthAndShields(abilityDuo[2].first);
	}

}

int HostileEntity::getTier()
{
	return tier;
}


