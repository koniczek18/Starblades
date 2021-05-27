#include "Game.h"

void Game::variablesInit()
{
	gameState = 0;
}

Game::Game()
{
	variablesInit();
}

Game::~Game()
{

}

const unsigned int Game::getGameState()
{
	return this->gameState;
}

void Game::changeGameState(int a)
{
	if (a >= 0)
	{
		this->gameState = a;
		std::cout << "Game state changed to :" << a << std::endl;
	}
	else
	{
		std::cout << "Error averted, tried to change game state to: " << a << std::endl;
		std::cout << "Current game state: " << gameState << std::endl;
	}
}
