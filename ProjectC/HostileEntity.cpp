#include "HostileEntity.h"

HostileEntity::HostileEntity()
{
	ID = 0;
	name = "Default";
	tier = 0;
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
	abilityDuoA[_no] = _value1;
	abilityDuoB[_no] = _value2;
}


void HostileEntity::play(sf::Text& tekst,Entity &player)
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
				if ((abilityDuoA[i-5]!=0)||(abilityDuoB[i-5] != 0))
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
	lastPlayed = abilityID[playCode];
	playEffect(abilityID[playCode],tekst,player);



}

void HostileEntity::playEffect(int _code,sf::Text& tekst,Entity &player)
{
	if (_code == 0)
	{
		float a = ability[0] * this->getX();
		int b = (int)a;
		player.receiveDamage(b);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik atakuje...";
		tekst.setString(s.str());
	}
	else if (_code == 1)
	{
		this->restoreHealth(ability[1]);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik sie podleczyl...";
		tekst.setString(s.str());
	}
	else if (_code == 2)
	{
		this->restoreShields(ability[2]);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik odnowil sobie oslony...";
		tekst.setString(s.str());
	}
	else if (_code == 3)
	{
		player.reduceX(ability[3] / 100);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik sabotuje twoj statek...";
		tekst.setString(s.str());
	}
	else if (_code == 4)
	{
		this->addX(ability[4] / 100);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik mobilizuje sily...";
		tekst.setString(s.str());
	}
	else if (_code == 5)
	{
		this->addX(abilityDuoA[0] / 100);
		float a = abilityDuoB[0] * this->getX();
		int b = (int)a;
		player.receiveDamage(b);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik mobilizuje sily i atakuje!";
		tekst.setString(s.str());
	}
	else if (_code == 6)
	{
		this->addX(abilityDuoA[1] / 100);
		this->restoreHealthAndShields(abilityDuoB[1]);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik naprawia swoj statek i leczy zaloge...";
		tekst.setString(s.str());
	}
	else if (_code == 7)
	{
		float a = abilityDuoB[2] * this->getX();
		int b = (int)a;
		player.receiveDamage(b);
		this->restoreHealthAndShields(abilityDuoA[2]);
		std::ostringstream s(std::ostringstream::ate);
		s << "Przeciwnik atakuje i regeneruje sily...";
		tekst.setString(s.str());
	}

}

int HostileEntity::getTier()
{
	return tier;
}


