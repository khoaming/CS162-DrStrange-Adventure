// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Portal class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Portal.hpp"


// *****************************************************************************
// Portal()
//
// This is the default constructor of a Portal.
// *****************************************************************************
Portal::Portal()
{
    destination = ' ';
    fullyOpened = false;
    hidden = false;
    walkable = fullyOpened;
    isPortal = true;

}

// *****************************************************************************
// Portal::Portal(char p_destination, bool p_hidden, bool p_fullyOpened, string
//         p_openSpell, int p_destRow, int p_destCol)
//
// This is a constructor of the Portal class that sets data members that are
// unique to the class.
// *****************************************************************************
Portal::Portal(char p_destination, bool p_hidden, bool p_fullyOpened,
               string p_openSpell, int p_destRow, int p_destCol)
{
    destination = p_destination;
    hidden = p_hidden;
    fullyOpened = p_fullyOpened;
    openSpell = p_openSpell;
    walkable = fullyOpened;
    isPortal = true;
    destRow = p_destRow;
    destCol = p_destCol;
}

int Portal::getDestRow()
{
    return destRow;
}

int Portal::getDestCol()
{
    return destCol;
}

char Portal::getDestination()
{
    return destination;
}

string Portal::getOpenSpell()
{
    return openSpell;
}

void Portal::setHidden(bool p_hidden)
{
    hidden = p_hidden;
}

void Portal::setFullyOpened(bool p_fullyOpened)
{
    walkable = fullyOpened = p_fullyOpened;
}

// *****************************************************************************
// print
//
// This function is to get the data that will be printed out by the overloaded
// << operator. The Portal will be displayed based on whether the Portal is
// hidden and fully opened or not.
// *****************************************************************************
std::ostream& Portal::print(std::ostream& out) const
{
    if (hidden)
    {
        out << "#";
    }
    else
    {
        if (fullyOpened)
        {
            out << "O";
        }
        else
        {
            out << "o";
        }
    }
    return out;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void Portal::interact()
{
    if (fullyOpened)
    {
        cout << "Voila, the portal is wide open! I should check what is on the other side!" << endl;
    }
    else
    {
        cout << "Hum, I have a glimpse of the other side but the portal is too small for me to get through!" << endl;
    }
}
