#include "Entity.h"

Entity::Entity()
{
	
}

Entity::Entity(std::string type)
{
}

Entity::~Entity()
{
}

void Entity::setBaseStats(int _health, int _shield, int _X)
{
	baseStats.health = _health;
	baseStats.shields = _shield;
	baseStats.multiX = (_X/static_cast<float>(100));
}

void Entity::setMaxStats(int _health, int _shield, int _X)
{
	maxStats.health = _health;
	maxStats.shields = _shield;
	maxStats.multiX = (_X/ static_cast<float>(100));
}

void Entity::resetCurrentStats()
{
	currentStats.health = maxStats.health;
	currentStats.shields = maxStats.shields;
	currentStats.multiX = maxStats.multiX;
}

void Entity::receiveDamage(int dmg)
{
	if (currentStats.shields == 0)
	{
		receiveDamageH(dmg);
	}
	else
	{
		if (currentStats.shields >= dmg)
		{
			receiveDamageS(dmg);
		}
		else
		{
			int toHealth = dmg - currentStats.shields;
			receiveDamageS(currentStats.shields);
			receiveDamageH(toHealth);
		}
	}
}

void Entity::receiveDamageH(int dmgH)
{
	currentStats.health -= dmgH;
	updateAndCheck();
}

void Entity::receiveDamageS(int dmgS)
{
	currentStats.shields -= dmgS;
	updateAndCheck();
}

void Entity::restoreHealthAndShields(int health)
{
	if (currentStats.health == maxStats.health)
	{
		restoreShields(health);
	}
	else
	{
		if (currentStats.health + health > maxStats.health)
		{
			restoreShields(health + currentStats.health - maxStats.health);
			currentStats.health = maxStats.health;
		}
	}
}

void Entity::restoreHealth(int health)
{
	currentStats.health += health;
	updateAndCheck();
}

void Entity::restoreShields(int shields)
{
	currentStats.shields += shields;
	updateAndCheck();
}

void Entity::repairShields()
{
	currentStats.shields = maxStats.shields;
	updateAndCheck();
}

void Entity::updateAndCheck()
{
	if (currentStats.health > maxStats.health)
	{
		currentStats.health = maxStats.health;
	}
	if (currentStats.shields > maxStats.shields)
	{
		currentStats.shields = maxStats.shields;
	}
	if (currentStats.health < 0)
	{
		currentStats.health = 0;
	}
	if (currentStats.shields < 0)
	{
		currentStats.shields = 0;
	}
	if (currentStats.health == 0)
	{
		isAlive = false;
	}
}

void Entity::addPower(int _power)
{
	power += _power;
}

void Entity::reducePower(int _power)
{
	power -= _power;
}

void Entity::addX(int _X)
{
	currentStats.multiX += (static_cast<float>(_X) / static_cast<float>(100));
	if (currentStats.multiX > 2.0)
	{
		currentStats.multiX = 2.0;
	}
}

void Entity::reduceX(int _X)
{
	currentStats.multiX -= (static_cast<float>(_X) / static_cast<float>(100));
	if (currentStats.multiX < 0.15)
	{
		currentStats.multiX = 0.15;
	}
}

void Entity::setX(int _X)
{
	currentStats.multiX = (static_cast<float>(_X)/ static_cast<float>(100));
	if (currentStats.multiX < 0.15)
	{
		currentStats.multiX = 0.15;
	}
}

int Entity::getHealth()
{
	return currentStats.health;
}

int Entity::getShields()
{
	return currentStats.shields;
}

int Entity::getPower()
{
	return power;
}

float Entity::getX()
{
	return currentStats.multiX;
}

float Entity::getPercentageVaule(bool wantHealth)
{
	if (maxStats.health == 0)
	{
		return 0;
	}
	else if (wantHealth == true)
	{
		
		return (static_cast<float>(currentStats.health) / static_cast<float>(maxStats.health));
	}
	else
	{
		float a = (static_cast<float>(currentStats.shields) / static_cast<float>(maxStats.shields));
		return a;
	}
}

bool Entity::returnAlive()
{
	return isAlive;
}

bool Entity::areShieldsUp()
{
	if (currentStats.shields > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Entity::compareHealth(int _health, bool more) //more than given value
{
	if (more == true)
	{
		if (currentStats.health > _health)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (currentStats.health <= _health)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Entity::compareShields(int _shields, bool more)
{
	if (more == true)
	{
		if (currentStats.shields > _shields)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (currentStats.shields <= _shields)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Entity::compareX(float _X, bool more)
{
	if (more == true)
	{
		if (currentStats.multiX > _X)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (currentStats.multiX <= _X)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Entity::setClass(std::string klasa)
{
	if (klasa == "Odyssey")
	{
		setBaseStats(100, 100, 100);
		setMaxStats(100, 100, 100);
		resetCurrentStats();
	}
	else if (klasa == "Curiosity")
	{
		setBaseStats(50, 150, 100);
		setMaxStats(50, 150, 100);
		resetCurrentStats();
	}
	else if (klasa == "Rouge")
	{
		setBaseStats(75, 100, 100);
		setMaxStats(75, 100, 100);
		resetCurrentStats();
	}
}

void Entity::FromFile(std::string _path, bool _isAnimated, int width,int no)
{
	path = _path;
	tekstura.loadFromFile(path);
	if (_isAnimated == true)
	{
		isAnimated = true;
		widthOfAnimation = width;
		numberOfFrames = no;
		createFrames();
	}

}

void Entity::createFrames()
{
	for (int i = 0; i < numberOfFrames; i++)
	{
		frames.emplace_back(widthOfAnimation * i, 0, widthOfAnimation, widthOfAnimation);
	}
}

void Entity::Animate()
{
	if (isAnimated == true)
	{
		this->setTextureRect(frames[index]);
		index++;
		if (index > numberOfFrames - 1)
		{
			index = 0;
		}
	}
	else if (movementAni == true)
	{
		if (movingUp == true)
		{
			if (index < 20)
			{
				this->move(0, -1);
				index++;
			}
			else
			{
				movingUp = false;
			}
		}
		else if (movingUp == false)
		{
			if (index > -20)
			{
				this->move(0, 1);
				index--;
			}
			else
			{
				movingUp = true;
			}
		}
		this->setTexture(tekstura, true);
	}
	else
	{
		this->setTexture(tekstura, true);
	}
}

void Entity::activateMovementAnimations()
{
	movementAni = true;
	int temp = rand() % 41 + (-20);
	if (temp < 0)
	{
		movingUp = true;
	}
	else
	{
		movingUp = true;
	}
	index = temp;
	setTexture(tekstura, true);
}

void Entity::modifyX(int _X)
{
	currentStats.multiX += (static_cast<float>(_X)/100.0);
	if (currentStats.multiX > 2.0)
	{
		currentStats.multiX = 2.0;
	}
	else if (currentStats.multiX < 0.5)
	{
		currentStats.multiX = 0.5;
	}
}

void Entity::restetX()
{
	currentStats.multiX = baseStats.multiX;
}