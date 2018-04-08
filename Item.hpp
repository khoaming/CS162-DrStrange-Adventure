// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Item class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef ITEM_HPP
#define ITEM_HPP

#include "Utilities.hpp"

class Item
{
protected:
    string name;
    string description;
    char display;
    bool canBePickedUp;
    
    int rowInSpace;
    int colInSpace;
    
public:
    Item(string p_name, string p_description, char p_display, bool p_canBePickedUp, int row, int col);

    string getName();
    string getDescription();
    int getRow();
    int getCol();
    bool getCanBePickedUp();
    char getDisplay();
    
    void interact();
    
    friend std::ostream& operator<<(std::ostream& out, const Item& p_item);
    std::ostream& print(std::ostream& out) const;
};

#endif 
