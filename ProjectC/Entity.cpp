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
}

void Entity::receiveDamageS(float dmgS)
{
	currentStats.shields -= dmgS;
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
}

void Entity::restoreShields(float shields)
{
	currentStats.shields += shields;
}
