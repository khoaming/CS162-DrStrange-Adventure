// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Wall class. All data
// members and functions of the class are defined here.
// *****************************************************************************
#include "Wall.hpp"


// *****************************************************************************
// Wall()
//
// This is the default constructor of a Wall.
// *****************************************************************************
Wall::Wall()
{
    display = '#';
    walkable = false;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void Wall::interact()
{
    cout << "Common Strange, there is nothing strange with a wall!" << endl;
}
