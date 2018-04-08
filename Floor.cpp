// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Floor class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Floor.hpp"

// *****************************************************************************
// Floor()
//
// This is the default constructor of an Floor.
// *****************************************************************************
Floor::Floor()
{
    display = '.';
    walkable = true;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void Floor::interact()
{
    cout << "Hum this place is strangely empty!" << endl;
}
