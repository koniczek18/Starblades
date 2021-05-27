//SFML
#include <SFML/Graphics.hpp>

#pragma once

class AnimatedSprite:public sf::Sprite
{
private:
	int animationFPS;
public:
	AnimatedSprite(int animation_FPS);
	~AnimatedSprite();
	void add_animation_frame(const sf::IntRect &rect);
	void step(const sf::Time& elapsed_time);
	
};

