#include "Unit.h"

void Unit::varInit(int a)
{
	if (a == 1)
	{
		name = "Warrior";
		baseStats.dmgMult = 1;
		baseStats.health = 50;
		baseStats.shields = 100;
		baseStats.handCapacity = 3;
		resetStats();
		setMax(1, baseStats.health);
		setMax(2, baseStats.shields);
		setMax(3, baseStats.handCapacity);
		setMax(4, baseStats.dmgMult);
	}
}

void Unit::resetStats()
{
	currentStats.health = baseStats.health;
	currentStats.shields = baseStats.shields;
	currentStats.dmgMult = baseStats.dmgMult;
	currentStats.handCapacity = baseStats.handCapacity;
}

void Unit::setMax(int a, float b)
{
	if (a == 1)
	{
		maxStats.health = b;
	}
	if (a == 2)
	{
		maxStats.shields = b;
	}
	if (a == 3)
	{
		maxStats.handCapacity = b;
	}
	if (a == 4)
	{
		maxStats.dmgMult = b;
	}
}

void Unit::takeDamage(int a)
{
	if (a > 0)
	{
		if (currentStats.shields == 0)
		{
			currentStats.health -= a;
			std::cout << "Health deducted from: " << name << ", by " << a << ", current health: " << currentStats.health << std::endl;
		}
		else
		{
			if (currentStats.shields - a >= 0)
			{
				currentStats.shields -= a;
				std::cout << "Shields deducted from: " << name << ", by " << a << ", current shields: " << currentStats.shields << std::endl;
			}
			else
			{
				int temp = a = currentStats.shields;
				currentStats.shields = 0;
				currentStats.health -= a;
				std::cout << "Shields broken for: " << name << ", delt excess damage (" << temp << ") to health, current health: " << currentStats.health << std::endl;
			}
		}
	}
}

void Unit::restoreHealth(int a)
{
	if (a > 0)
	{
		currentStats.health += a;
		if (currentStats.health > maxStats.health)
		{
			currentStats.health = maxStats.health;
			std::cout << "Attempted overheal on: " << name << ", current health: " << currentStats.health << std::endl;
		}
		else
		{
			std::cout << "Health (+" << a << ")added to: " << name << ", current health: " << currentStats.health << std::endl;
		}
	}
	else
	{
		std::cout << "Attempted to add negative ammounts of health to: " << name << ", error averted" << std::endl;
	}
}

void Unit::restoreShields(int a)
{
	if (a > 0)
	{
		currentStats.shields += a;
		if (currentStats.shields > maxStats.shields)
		{
			currentStats.shields = maxStats.shields;
			std::cout << "Attempted shield overcharge on: " << name << ", current shields: " << currentStats.shields << std::endl;
		}
		else
		{
			std::cout << "Shields (+" << a << ")added to: " << name << ", current shields: " << currentStats.shields << std::endl;
		}
	}
	else
	{
		std::cout << "Attempted to add negative ammounts of shields to: " << name << ", error averted" << std::endl;
	}
}

void Unit::addEffect(int ID, int x, int y)
{
	statuses.emplace_back(std::make_tuple(ID,x,y));
	std::cout << "Added effect to: " << name << ", ID: " << ID << ", str.: " << x << ", duration: "<<y << std::endl;
}

const bool Unit::isAlive()
{
	if (currentStats.health < 1)
	{
		std::cout << "Status check: isAlive - " << name << ", returned false" << std::endl;
		return false;
    }
	else
	{
		std::cout << "Status check: isAlive - " << name << ", returned true" << std::endl;
		return true;
	}
}
