// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Square class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Square.hpp"

// *****************************************************************************
// Square()
//
// This is the default constructor of an Square.
// *****************************************************************************
Square::Square()
{
    display = '.'; // empty
    walkable = true;
    isPortal = false;
    character = NULL;
    item   = NULL;
}

// *****************************************************************************
// ~Square()
//
// This is the destructor of a Square. It frees dynamically allocated memory.
// *****************************************************************************
Square::~Square()
{
    if (character!= NULL)
    {
        delete character;
        character = NULL;
    }
    
    if (item!= NULL)
    {
        delete item;
        item = NULL;
    }
}

// *****************************************************************************
// setCharacter(Character* p_character)
//
// This function sets a Character on a Square and changes whether the Square
// is walkable.
// *****************************************************************************
void Square::setCharacter(Character* p_character)
{
    character = p_character;
    
    if (p_character == NULL)
    {
        walkable = true;
    }
    else
    {
        walkable = false;
    }

}

// *****************************************************************************
// setItem(Item* p_item)
//
// This function sets an Item on a Square and changes whether the Square is
// walkable.
// *****************************************************************************
void Square::setItem(Item* p_item)
{
    item = p_item;
    
    if (p_item == NULL)
    {
        if (display == '#' || display == 'T' || display == 'Y')
        {
            walkable = false;
        }
        else
        {
           walkable = true;
        }
    }
    else if (display == 'Y' && p_item->getDisplay() == '|') // put a ladder on a wall
    {
        walkable = true;
    }
    else
    {
        walkable = false;
    }
}

char Square::getDisplay()
{
    return display;
}

Item* Square::getItem()
{
    return item;
}

Character* Square::getCharacter()
{
    return character;
}

bool Square::getWalkable()
{
    return walkable;
}

bool Square::getIsPortal()
{
    return isPortal;
}

// *****************************************************************************
// hasItem()
//
// This function returns a boolean whether the Square has an Item on it.
// *****************************************************************************
bool Square::hasItem()
{
    return item != NULL;
}

// *****************************************************************************
// hasCharacter()
//
// This function returns a boolean whether the Square has a Character on it.
// *****************************************************************************
bool Square::hasCharacter()
{
    return character != NULL;
}

// *****************************************************************************
// Overloaded Operator <<
//
// This function will overload the operator << for Square objects. When the <<
// is used, it will print out the display of a Square depending on whether there
// is a Character, or an Item on the Square. See below print function.
// *****************************************************************************
std::ostream& operator<<(std::ostream& out, const Square& p_square)
{
    return p_square.print(out);
}

// *****************************************************************************
// print
//
// This function is to get the data that will be printed out by the overloaded
// << operator. The Square will be displayed based on the prioritization order
// of Character, Item, and Square's display char. This will be overidden in the
// Portal derived class.
// *****************************************************************************
std::ostream& Square::print(std::ostream& out) const
{
    if (character != NULL)
    {
        out << *character;
    }
    else if (item != NULL)
    {
        out << *item;
    }
    else
    {
        out << display;
    }
    
    return out;
}
