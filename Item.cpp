// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Item class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Item.hpp"

// *****************************************************************************
// Item(string p_name, string p_description, char p_display, bool p_canBePickedUp,
//      int row, int col)
//
// This is a constructor of an Item that sets up its data members based on the
// parameters.
// *****************************************************************************
Item::Item(string p_name, string p_description, char p_display, bool p_canBePickedUp, int row, int col)
{
    name = p_name;
    description = p_description;
    display = p_display;
    canBePickedUp = p_canBePickedUp;
    rowInSpace = row;
    colInSpace = col;
}

string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return description;
}

int Item::getRow()
{
    return rowInSpace;
}

int Item::getCol()
{
    return colInSpace;
}

bool Item::getCanBePickedUp()
{
    return canBePickedUp;
}

char Item::getDisplay()
{
    return display;
}

// *****************************************************************************
// Overloaded Operator <<
//
// This function will overload the operator << for Item objects. When the <<
// is used, it will print out the display of an Item.
// *****************************************************************************
std::ostream& operator<<(std::ostream& out, const Item& p_item)
{
    return p_item.print(out);
}

// *****************************************************************************
// print
//
// This function is to get the data that will be printed out by the overloaded
// << operator. 
// *****************************************************************************
std::ostream& Item::print(std::ostream& out) const
{
    out << display;
    return out;
}

// *****************************************************************************
// interact()
//
// This function displays the description of an Item when Strange interacts with
// it.
// *****************************************************************************
void Item::interact()
{
    cout << description << endl;
}
