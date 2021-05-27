//STD
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <tuple>

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//CLASSES
#include "WindowState.h"

//MAIN CODE
int main() 
{
    WindowState windowState;

    while (windowState.isWindowOpen())
    {
        //Update
        windowState.update();

        //Render
        windowState.render();
    }

    return 0;
}