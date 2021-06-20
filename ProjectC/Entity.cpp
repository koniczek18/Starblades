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

void Entity::setBaseStats(float _health, float _shield, float _X)
{
	baseStats.health = _health;
	baseStats.shields = _shield;
	baseStats.multiX = _X;
}

void Entity::setMaxStats(float _health, float _shield, float _X)
{
	maxStats.health = _health;
	maxStats.shields = _shield;
	maxStats.multiX = _X;
}

void Entity::resetCurrentStats()
{
	currentStats.health = maxStats.health;
	currentStats.health = maxStats.shields;
	currentStats.multiX = maxStats.multiX;
}

void Entity::receiveDamage(float dmg)
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
			float toHealth = dmg - currentStats.shields;
			receiveDamageS(currentStats.shields);
			receiveDamageH(toHealth);
		}
	}
}

void Entity::receiveDamageH(float dmgH)
{
	currentStats.health -= dmgH;
	updateAndCheck();
}

void Entity::receiveDamageS(float dmgS)
{
	currentStats.shields -= dmgS;
	updateAndCheck();
}

void Entity::restoreHealthAndShields(float health)
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

void Entity::restoreHealth(float health)
{
	currentStats.health += health;
	updateAndCheck();
}

void Entity::restoreShields(float shields)
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

void Entity::setX(float _X)
{
	currentStats.multiX = _X;
}

float Entity::getHealth()
{
	return currentStats.health;
}

float Entity::getShields()
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
	if (wantHealth == true)
	{
		return currentStats.health / maxStats.health;
	}
	else
	{
		return currentStats.shields / maxStats.shields;
	}
}

bool Entity::compareHealth(float _health, bool more) //more than given value
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

bool Entity::compareShields(float _shields, bool more)
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


