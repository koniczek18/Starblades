#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <time.h>
#include <random>

#pragma once
class BouncingStar:public sf::Sprite
{
private:
	float velocityX = 0;
	float velocityY = 0;
	float velocityAng = 0;
	float topLimiter = 0;
	float bottomLimiter = 0;
	float leftLimiter = 0;
	float rightLimiter = 0;
	void bounce();
	

public:
	BouncingStar(float a,float b);
	~BouncingStar();
	void animate(const sf::Time& elapsed);
	void setBounds(float a, float b, float c, float d);


};