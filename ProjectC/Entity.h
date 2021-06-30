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

class Entity:public sf::Sprite
{
private:
	stats baseStats;
	stats maxStats;
	stats currentStats;
	int power;
	bool isAlive = true;

	sf::Texture tekstura;
	std::vector<sf::IntRect> frames;
	bool isAnimated = false;
	int widthOfAnimation = 0;
	int numberOfFrames = 0;
	std::string path = "1.png";
	int index = 0;
	bool movingUp = true;
	bool movementAni = false;

public:
	Entity();
	Entity(std::string type);
	~Entity();

	void setBaseStats(int _health, int _shields, int _X);
	void setMaxStats(int _health, int _shield, int _X);
	void resetCurrentStats();

	void receiveDamage(int _dmg);
	void receiveDamageH(int _dmgH);
	void receiveDamageS(int _dmgS);

	void restoreHealthAndShields(int _health);
	void restoreHealth(int _health);
	void restoreShields(int _shields);
	void repairShields();

	void updateAndCheck();

	void addPower(int _power);
	void reducePower(int _power);

	void addX(int _X);
	void reduceX(int _X);
	void setX(int _X);

	int getHealth();
	int getShields();
	int getPower();
	float getX();
	float getPercentageVaule(bool wantHealth);

	bool returnAlive();
	bool areShieldsUp();
	bool compareHealth(int _health, bool more);
	bool compareShields(int _shields, bool more);
	bool compareX(float _X, bool more);

	void setClass(std::string klasa);

	void FromFile(std::string _path,bool _isAnimated,int width,int no);
	void createFrames();
	void Animate();

	void activateMovementAnimations();

};

