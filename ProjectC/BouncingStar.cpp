#include "BouncingStar.h"

void BouncingStar::bounce()
{
	{
		if (this->getGlobalBounds().top < topLimiter)
		{
			velocityY = abs(velocityY);
		}
		if ((this->getGlobalBounds().top + this->getGlobalBounds().height) > bottomLimiter)
		{
			velocityY = -1 * abs(velocityY);
		}
		if (this->getGlobalBounds().left < leftLimiter)
		{
			velocityX = abs(velocityX);
		}
		if ((this->getGlobalBounds().left + this->getGlobalBounds().width) > rightLimiter)
		{
			velocityX = -1 * abs(velocityX);
		}
	}
}

BouncingStar::BouncingStar(float a, float b)
{
	this->setBounds(0, 1280, 0, 720);
	this->velocityX = 30;
	this->velocityY = 30;
	this->velocityAng = rand()% 41 - 20;
	this->setColor(sf::Color(sf::Color(rand() % 255, rand() % 255, rand() % 255)));
	this->setPosition(rand() % 1280 + 1, rand() % 720 + 1);
	this->setScale(a, b);
}

BouncingStar::~BouncingStar()
{
}

void BouncingStar::animate(const sf::Time& elapsed)
{
	bounce();
	move(velocityX * elapsed.asSeconds(), velocityY * elapsed.asSeconds());
	rotate(velocityAng * elapsed.asSeconds());
}

void BouncingStar::setBounds(float a, float b, float c, float d)
{
	leftLimiter = a;
	rightLimiter = b;
	topLimiter = c;
	bottomLimiter = d;
}

