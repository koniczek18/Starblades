//STD
#include <iostream>

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#pragma once

class WindowState
{
private:
	//Variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	//Private Functions
	void VarInit();
	void InitWind();

public:
	//Constructor|Destructor
	WindowState();
	~WindowState();

	//Accessors
	const bool isWindowOpen();

	//Functions
	void update();
	void updateEv();
	void render();



};

