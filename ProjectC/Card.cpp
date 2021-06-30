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


void Card::settier(int a)
{
	tier = a;
}

void Card::setTextureFromFile(std::string _path)
{
	path = _path;
	tekstura.loadFromFile(path);
	resetTexture();
}

void Card::play(Entity &owner, Entity &target)
{
	target.receiveDamage(data[0]*owner.getX());
	owner.receiveDamage(data[1]);
	target.receiveDamageS(data[2] * owner.getX());
	owner.receiveDamageS(data[3]);
	target.receiveDamageH(data[4] * owner.getX());
	owner.receiveDamageH(data[5]);
	target.restoreHealthAndShields(data[6]);
	owner.restoreHealthAndShields(data[7]);
	target.restoreShields(data[8]);
	owner.restoreShields(data[9]);
	target.restoreHealth(data[10]);
	owner.restoreShields(data[11]);
	target.modifyX(data[12]);
	owner.modifyX(data[13]);
}

//void Card::play(Entity& owner, Entity& target,Jukebox &jukebox)
//{
//	target.receiveDamage(data[0] * owner.getX());
//	owner.receiveDamage(data[1]);
//	target.receiveDamageS(data[2] * owner.getX());
//	owner.receiveDamageS(data[3]);
//	target.receiveDamageH(data[4] * owner.getX());
//	owner.receiveDamageH(data[5]);
//	target.restoreHealthAndShields(data[6]);
//	owner.restoreHealthAndShields(data[7]);
//	target.restoreShields(data[8]);
//	owner.restoreShields(data[9]);
//	target.restoreHealth(data[10]);
//	owner.restoreShields(data[11]);
//	target.modifyX(data[12]);
//	owner.modifyX(data[13]);
//
//	if (soundID != -1)
//	{
//		jukebox.play(soundID);
//	}
//}

void Card::setPositionTo(int pos)
{
	if (pos == 1)
	{
		this->setPosition(400.0f, 400.0f);
	}
	else if (pos == 2)
	{
		this->setPosition(700.0f, 400.0f);
	}
	else if (pos == 3)
	{
		this->setPosition(900.0f, 400.0f);
	}
}

void Card::setSoundID(int ID)
{
	if((ID>=0)&&(ID<=10))
	soundID = ID;
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

int Card::gettier()
{
	return tier;
}

std::string Card::returnPath()
{
	return path;
}

void Card::operator=(Card& kard)
{
	this->ID = kard.getID();
	this->name = kard.getName();
	for (int i = 0; i < 14; i++)
	{
		this->data[i] = getData(i);
	}
	this->tier = kard.gettier();
	this->path = kard.returnPath();
	this->resetTexture();
}

void Card::changePosition(int i)
{
	position = i;
	if (position == 0)
	{
		this->setPosition(-200, -200);
	}
	else if(position == 1)
	{
		this->setPosition(440 - (0.5 * this->getGlobalBounds().width), 400);
	}
	else if (position == 2)
	{
		this->setPosition(640-(0.5*this->getGlobalBounds().width), 400);
	}
	else if (position == 3)
	{
		this->setPosition(840 - (0.5 * this->getGlobalBounds().width), 400);
	}
}

void Card::resetTexture()
{
	if (path == "null")
	{
		tekstura.loadFromFile("assets/cards/2.png");
		setTexture(tekstura);
	}
	else
	{
		tekstura.loadFromFile(path);
		setTexture(tekstura);
	}
}
