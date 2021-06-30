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
	baseStats.multiX = (_X/100);
}

void Entity::setMaxStats(int _health, int _shield, int _X)
{
	maxStats.health = _health;
	maxStats.shields = _shield;
	maxStats.multiX = (_X/100);
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

void Entity::addX(float _X)
{
	currentStats.multiX += _X;
}

void Entity::reduceX(float _X)
{
	currentStats.multiX -= _X;
}

void Entity::setX(int _X)
{
	currentStats.multiX = (_X/100);
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
		setBaseStats(100.0f, 100.0f, 1.0f);
		setMaxStats(100.0f, 100.0f, 1.0f);
		resetCurrentStats();
	}
	else if (klasa == "Curiosity")
	{
		setBaseStats(50.0f, 150.0f, 1.2f);
		setMaxStats(50.0f, 150.0f, 1.2f);
		resetCurrentStats();
	}
	else if (klasa == "Rouge")
	{
		setBaseStats(75.0f, 100.0f, 1.5f);
		setMaxStats(75.0f, 100.0f, 1.5f);
		resetCurrentStats();
	}
}

bool Entity::areShieldsUp()
{
	if (currentStats.shields != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


