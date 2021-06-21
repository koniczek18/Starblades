#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#pragma once

struct stats
{
	int health;
	int shields;
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

	void setBaseStats(int _health, int _shields, float _X);
	void setMaxStats(int _health, int _shield, float _X);
	void resetCurrentStats();

	void receiveDamage(int _dmg);
	void receiveDamageH(int _dmgH);
	void receiveDamageS(int _dmgS);

	void restoreHealthAndShields(int _health);
	void restoreHealth(int _health);
	void restoreShields(int _shields);

	void updateAndCheck();

	void addPower(int _power);
	void reducePower(int _power);

	void addX(float _X);
	void reduceX(float _X);
	void setX(float _X);

	int getHealth();
	int getShields();
	int getPower();
	float getX();
	int getPercentageVaule(bool wantHealth);

	bool returnAlive();
	bool areShieldsUp();
	bool compareHealth(int _health, bool more);
	bool compareShields(int _shields, bool more);
	bool compareX(float _X, bool more);

	void setClass(std::string klasa);

};

