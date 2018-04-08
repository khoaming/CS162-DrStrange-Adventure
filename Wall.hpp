// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Wall class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef WALL_HPP
#define WALL_HPP

#include "Square.hpp"

class Wall : public Square
{
public:
    Wall();
    void interact();
};

#endif
