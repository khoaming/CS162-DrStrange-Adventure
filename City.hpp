// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the City class. All data members
// and functions of the class are declared here.
// *****************************************************************************
#ifndef CITY_HPP
#define CITY_HPP

#include "Space.hpp"

class City : public Space
{
private:
    
public:
    City(string p_name, int p_length, int p_width, char boundary);
    void whereIsThis();
};

#endif
