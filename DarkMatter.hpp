// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the DarkMatter class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef DARKMATTER_HPP
#define DARKMATTER_HPP

#include "Square.hpp"

class DarkMatter : public Square
{
public:
    DarkMatter();
    void interact();
};

#endif
