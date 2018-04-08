// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the DrStrange class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef DRSTRANGE_HPP
#define DRSTRANGE_HPP

#include "Character.hpp"

class DrStrange : public Character
{
private:
    bool flying;
public:
    DrStrange(string p_name, string p_conversation1, string p_conversation2,
              string p_conversation3, string p_key, string p_key2,
              direction p_dir, int row, int col, int p_capacity);
    
    bool getFlying();
    bool canPickMoreItem();
    void addItem(Item* item);
    void useItem();
    Item* giveOrPutOrUseItem();
};

#endif
