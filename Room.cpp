// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Room class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Room.hpp"

// *****************************************************************************
// Room(string p_name, int p_length, int p_width, char boundary)
//
// This is a constructor of a Room that calls the constructor of the Space
// base class.
// *****************************************************************************
Room::Room(string p_name, int p_length, int p_width, char boundary) : Space(p_name, p_length, p_width, boundary)
{
    
}

// *****************************************************************************
// whereIsThis()
//
// This overides the pure virtual whereIsThis() function of the Space base class.
// It displays the name of the Room.
// *****************************************************************************
void Room::whereIsThis()
{
    cout << "Strange, you are currently in " << name << " room!" << endl;
}
