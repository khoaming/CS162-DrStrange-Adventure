// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Character class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Character.hpp"

// *****************************************************************************
// Character::Character(string p_name, string p_conversation1, string p_conversation2,
//            string p_conversation3, string p_key, string p_key2,
//            direction p_dir, int p_capacity, int row, int col)
//
// This is a constructor of a Character that sets up its data members based on the
// parameters. The gameLogicSolved data member is defaulted to be false.
// *****************************************************************************
Character::Character(string p_name, string p_conversation1, string p_conversation2,
                     string p_conversation3, string p_key, string p_key2,
                     direction p_dir, int p_capacity, int row, int col)
{
    name = p_name;
    conversation1 = p_conversation1;
    conversation2 = p_conversation2;
    conversation3 = p_conversation3;
    keyToSolveGameLogic = p_key;
    keyItemForStrange = p_key2;
    dir = p_dir;
    rowInSpace = row;
    colInSpace = col;
    capacity = p_capacity;
    
    gameLogicSolved = false;
    
}

// *****************************************************************************
// ~Character()
//
// This is the destructor of a Character. It frees dynamically allocated memory.
// *****************************************************************************
Character::~Character()
{
    for (int i = 0; i < (signed) inventory.size(); i++)
    {
        if (inventory[i] != NULL)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

string Character::getName()
{
    return name;
}

int Character::getRow()
{
    return rowInSpace;
}

int Character::getCol()
{
    return colInSpace;
}

direction Character::getDirection()
{
    return dir;
}

void Character::setRow(int p_rowInSpace)
{
    rowInSpace = p_rowInSpace;
}

void Character::setCol(int p_colInSpace)
{
    colInSpace = p_colInSpace;
}

void Character::setDir(direction p_dir)
{
    dir = p_dir;
}

void Character::setGameLogicSolved(bool solved)
{
    gameLogicSolved = solved;
}

bool Character::getGameLogicSolved()
{
    return gameLogicSolved;
}

// *****************************************************************************
// go(char move)
//
// This function adjusts the row or col of the Character based on a given move.
// *****************************************************************************
void Character::go(char move)
{
    switch (move)
    {
        case 'a': dir = WEST,  colInSpace--; break;
        case 'd': dir = EAST,  colInSpace++; break;
        case 'w': dir = NORTH, rowInSpace--; break;
        case 's': dir = SOUTH, rowInSpace++; break;
    }
}

// *****************************************************************************
// canPickMoreItem()
//
// This function returns a boolean to indicate whether the Character can pick
// more item depending on its inventory's capacity.
// *****************************************************************************
bool Character::canPickMoreItem()
{
    bool can = ((signed)inventory.size() < capacity);
    
    if (!can)
    {
        cout << "Thank you but I can't take that!" << endl;
    }
    return can;
}

// *****************************************************************************
// canPickItem(Item* item)
//
// This function returns a boolean to indicate whether the Character can pick
// the specified Item. This is to prevent user from giving other characters
// important items.
// *****************************************************************************
bool Character::canPickItem(Item* item)
{
    bool can = (item->getName() == keyToSolveGameLogic);
    
    if (!can)
    {
        cout << "Thank you but I don't need that :)" << endl;
    }
    return can;
}

// *****************************************************************************
// addItem(Item* item)
//
// This function allows a Character to add an item to inventory depending on
// whether the Item is keyItemForStrange or keyToSolveGameLogic.
// *****************************************************************************
void Character::addItem(Item* item)
{
    if (item->getName() == keyItemForStrange) // for when initializing the Character
    {
        inventory.push_back(item);
    }
    else if (item->getName() == keyToSolveGameLogic) // for when Strange gives key logic item
    {
        delete item; // just delete it.
        item = NULL;
        gameLogicSolved = true;
    }
}

// *****************************************************************************
// putBackItem(Item* item)
//
// This function allows a Character to just put an Item back to its inventory.
// *****************************************************************************
void Character::putBackItem(Item* item)
{
    inventory.push_back(item);
}

// *****************************************************************************
// displayInventory()
//
// This function displays the inventory of a Character.
// *****************************************************************************
void Character::displayInventory()
{
    if (inventory.size() == 0)
    {
        cout << "Nothing is in your backpack!" << endl;
    }
    else
    {
        for (int i = 0; i < (signed) inventory.size(); i++)
        {
            cout << i + 1 << " - " << inventory[i]-> getName() << "\t- ";
            cout << inventory[i]->getDescription() << endl;
        }
    }
}

// *****************************************************************************
// canGiveItem()
//
// This function returns a boolean to indicate the first item can be given out
// to Strange. If the item in inventory is the key item, then can give. Can't
// when item is the one that was given by Strange.
// *****************************************************************************
bool Character::canGiveItem()
{
    return (inventory[0]->getName() != keyToSolveGameLogic);
}

// *****************************************************************************
// giveOrPutOrUseItem()
//
// This function allows a Character to give an Item to Strange. When it gives
// the item, it will set the capacity to 0 so that it will no longer take any
// item to prevent the user from accidentally giving important items.
// *****************************************************************************
Item* Character::giveOrPutOrUseItem()
{
    Item* toUse = inventory[0]; // key item to give should be the first one
    
    inventory.clear();
    
    capacity = 0; // so the character will not take any more item.
    
    return toUse;
}

// *****************************************************************************
// interact()
//
// This function displays a conversation line when Strange interacts with it
// depending on if the Character's game logic has been solved, and if the key
// item is being given to Strange.
// *****************************************************************************
void Character::interact()
{
    
    if (!gameLogicSolved)           // logic has not been solved
    {
        cout << conversation1 << endl;
    }
    else
    {
        if (!inventory.empty())     // handing key item to Strange
        {
            cout << conversation2 << endl;
        }
        else                        // not important to game logic anymore
        {
            cout << conversation3 << endl;
        }
    }
}

// *****************************************************************************
// Overloaded Operator <<
//
// This function will overload the operator << for Character objects. When the <<
// is used, it will print out all of the data of a Character.
// *****************************************************************************
std::ostream& operator<<(std::ostream& out, const Character& p_item)
{
    return p_item.print(out);
}

// *****************************************************************************
// print
//
// This function is to get the display char based on the current direction of
// the character that will be printed out by the overloaded << operator.
// *****************************************************************************
std::ostream& Character::print(std::ostream& out) const
{
    if (dir == NORTH)
    {
        out << '^';
    }
    else if (dir == SOUTH)
    {
        out << 'v';
    }
    else if (dir == WEST)
    {
        out << '<';
    }
    else // EAST
    {
        out << '>';
    }
    
    return out;
}

