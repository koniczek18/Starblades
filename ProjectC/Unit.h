#include <vector>
#include <map>
#include <utility>
#include <iostream>

#pragma once

struct Resistances
{
	int physical;
	int magical;
	int toxin;
	int electric;
	int celestial;
	int doom;
};

struct Data
{
	int health;
	int shields;
	int handCapacity;
	float dmgMult;
};

class Unit
{
private:
	//Variables - data
	std::string name;
	Data baseStats;
	Data currentStats;
	Data maxStats;
	Resistances resistances;
	std::vector<int> hand;
	std::vector<int> deck;
	std::map<int, int> avilCards;
	std::vector<std::tuple<int, int, int>> statuses;

	//Functions
	void varInit(int a);
	//void update();
	void resetStats();
	void setMax(int a, float b);


public:
	//Functions
	//Unit();
	//Unit(int a);
	//~Unit();
	void takeDamage(int a);
	void restoreHealth(int a);
	void restoreShields(int a);
	void addEffect(int ID, int x, int y);

	//Accessors
	const bool isAlive();


	
};

