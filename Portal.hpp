// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Portal class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Square.hpp"

class Portal : public Square
{
private:
    int destRow;
    int destCol;
    char destination;
    bool hidden;
    bool fullyOpened;
    string openSpell;
    

public:
    Portal();
    Portal(char p_destination, bool p_hidden, bool p_fullyOpened, string p_openSpell, int p_destRow, int p_destCol);
    void setFullyOpened(bool p_fullyOpened);
    void setHidden(bool p_hidden);
    int getDestRow();
    int getDestCol();
    char getDestination();
    string getOpenSpell();
    virtual std::ostream& print(std::ostream& out) const;
    virtual void interact();
};

#endif 
