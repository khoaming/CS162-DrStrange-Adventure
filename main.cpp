// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This program creates an Engine for the player to play the game.
// *****************************************************************************

#include "Engine.hpp"

// *****************************************************************************
// main
//
// This create an Engine and play the game once. Then asks if user want to play
// again.
// *****************************************************************************
int main()
{
    do
    {
        printIntro();
        
        Engine* engine = new Engine();
        
        engine->play();
        
        delete engine;
        
    } while (getCharYesNo("Play again (y/n)?: ") == 'y');
    
    return 0;
}
