#include "Card.h"

Card::Card()
{
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

void Card::setData(std::vector<float> _data)
{
	for (int i = 0; i < _data.size(); i++)
	{
		if (i < 14)
		{
			data[i] = _data[i];
		}
	}
}

void Card::setData(int _id, float value)
{
	if ((_id > -1) && (_id < 12))
	{
		data[_id] = value;
	}
}

void Card::setData(float _data[12])
{
	for (int i = 0; i < 14; i++)
	{
		data[i] = _data[i];
	}
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
