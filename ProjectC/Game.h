#include <iostream>

/*
Game states:
0) Main menu
1) Settings
2) New Game (Character select)
3) Shop
4) Path selection
5) Combat
6) Result screen
*/

#pragma once
class Game
{
private:
	//Variables
	unsigned int gameState;


	//Private Functions
	void variablesInit();

public:
	//Constructor|Destructor
	Game();
	~Game();

	//Accessors
	const unsigned int getGameState();

	//Functions
	void changeGameState(int a);

};

