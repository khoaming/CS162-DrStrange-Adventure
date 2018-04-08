// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Building class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Space.hpp"

class Building : public Space
{
private:
    
public:
    Building(string p_name, int p_length, int p_width, char boundary);
    void whereIsThis();
};

#endif 
