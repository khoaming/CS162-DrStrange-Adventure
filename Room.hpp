// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Room class. All data members
// and functions of the class are declared here.
// *****************************************************************************
#ifndef ROOM_HPP
#define ROOM_HPP

#include "Space.hpp"

class Room : public Space
{
private:
    
public:
    Room(string p_name, int p_length, int p_width, char boundary);
    void whereIsThis();
};

#endif /* Room_hpp */
