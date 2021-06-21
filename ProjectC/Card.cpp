#include "Card.h"

Card::Card()
{
	this->ID = 0;
	for (int i = 0; i < 14; i++)
	{
		data[i] = 0;
	}
	this->setPosition(-200, -200);
}

Card::~Card()
{
}

void Card::loadDataFromFile(std::string _path)
{
}

void Card::setData(std::vector<int> _data)
{
	for (int i = 0; i < _data.size(); i++)
	{
		if (i < 14)
		{
			data[i] = _data[i];
		}
	}
}

void Card::setData(int _id, int value)
{
	if ((_id > -1) && (_id < 12))
	{
		data[_id] = value;
	}
}

void Card::setData(int _data[12])
{
	for (int i = 0; i < 14; i++)
	{
		data[i] = _data[i];
	}
}

void Card::setID(int _id)
{
	ID = _id;
}

void Card::setName(std::string _name)
{
	name = _name;
}

void Card::setEffect(std::string a,int b)
{
	bonus = std::make_pair(a, b);
}

void Card::setRarity(int a)
{
	rarity = a;
}

void Card::setTextureFromFile(std::string _path)
{
	tekstura.loadFromFile(_path);
	this->setTexture(tekstura);
}

void Card::play(Entity &owner, Entity &target)
{
	target.receiveDamage(data[0]);
	owner.receiveDamage(data[1]);
	target.receiveDamageS(data[2]);
	owner.receiveDamageS(data[3]);
	target.receiveDamageH(data[4]);
	owner.receiveDamageH(data[5]);
	target.restoreHealthAndShields(data[6]);
	owner.restoreHealthAndShields(data[7]);
	target.restoreShields(data[8]);
	owner.restoreShields(data[9]);
	target.restoreHealth(data[10]);
	owner.restoreShields(data[11]);
	if (data[12] > 0)
	{
		target.addPower(data[12]);
	}
	else
	{
		target.reducePower(data[12]);
	}
	if (data[13] > 0)
	{
		owner.addPower(data[13]);
	}
	else
	{
		owner.reducePower(data[13]);
	}
}

void Card::setPositionTo(int pos)
{
	if (pos == 1)
	{
		this->setPosition(400, 400);
	}
	else if (pos == 2)
	{
		this->setPosition(700, 400);
	}
	else if (pos == 3)
	{
		this->setPosition(900, 400);
	}
}

int Card::getID()
{
	return ID;
}

std::string Card::getName()
{
	return name;
}

int Card::getData(int a)
{
	return data[a];
}

sf::Texture Card::returnTexture()
{
	return tekstura;
}

std::pair<std::string, int> Card::getBouns()
{
	return bonus;
}

int Card::getRarity()
{
	return rarity;
}

void Card::operator=(Card& kard)
{
	this->ID = kard.getID();
	this->name = kard.getName();
	for (int i = 0; i < 14; i++)
	{
		this->data[i] = getData(i);
	}
	this->tekstura = kard.returnTexture();
	this->bonus = kard.getBouns();
	this->rarity = kard.getRarity();
}

void Card::changePosition(int i)
{
	if (position == 0)
	{
		this->setPosition(-100, -100);
	}
	else if(position == 1)
	{
		this->setPosition(300, 300);
	}
	else if (position == 2)
	{
		this->setPosition(500, 300);
	}
	else if (position == 3)
	{
		this->setPosition(700, 300);
	}
}
