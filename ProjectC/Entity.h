#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#pragma once

struct stats
{
	float health;
	float shields;
	float multiX;
};

class Entity
{
private:
	stats baseStats;
	stats maxStats;
	stats currentStats;
	int power;

	bool isAlive = true;

public:
	Entity();
	Entity(std::string type);
	~Entity();

	void setBaseStats(float _health, float _shields, float _X);
	void setMaxStats(float _health, float _shield, float _X);
	void resetCurrentStats();

	void receiveDamage(float _dmg);
	void receiveDamageH(float _dmgH);
	void receiveDamageS(float _dmgS);

	void restoreHealthAndShields(float _health);
	void restoreHealth(float _health);
	void restoreShields(float _shields);

	void updateAndCheck();

	void addPower(int _power);
	void reducePower(int _power);

	void addX(float _X);
	void reduceX(float _X);
	void setX(float _X);

	float getHealth();
	float getShields();
	int getPower();
	float getX();
	float getPercentageVaule(bool wantHealth);

	bool returnAlive();
	bool areShieldsUp();
	bool compareHealth(float _health, bool more);
	bool compareShields(float _shields, bool more);
	bool compareX(float _X, bool more);

	void setClass(std::string klasa);

};

