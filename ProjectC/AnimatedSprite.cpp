#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int animation_FPS)
{
	{
		animationFPS = animation_FPS;
	}
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::add_animation_frame(const sf::IntRect& rect)
{

}

void AnimatedSprite::step(const sf::Time& elapsed_time)
{
}
