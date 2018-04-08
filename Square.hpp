// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Square class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Character.hpp"
#include "Item.hpp"
#include "Utilities.hpp"

class Square
{
protected:
    
    char display;
    bool walkable;
    bool isPortal;
    
    Character* character;
    Item* item;
    
public:
    Square();
    virtual ~Square();
    
    char getDisplay();
    Item* getItem();
    Character* getCharacter();
    
    void setCharacter(Character* p_character);
    void setItem(Item* p_item);
    
    bool hasItem();
    bool hasCharacter();
    bool getWalkable();
    bool getIsPortal();
    
    friend std::ostream& operator<<(std::ostream& out, const Square& p_square);
    virtual std::ostream& print(std::ostream& out) const;
    
    virtual void interact() = 0;
};

#endif 
