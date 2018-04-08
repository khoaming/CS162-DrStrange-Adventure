// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Character class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Utilities.hpp"
#include "Item.hpp"
#include <vector>
using std::vector;

class Character
{
protected:
    string name;
    string conversation1;
    string conversation2;
    string conversation3;
    string keyToSolveGameLogic;
    string keyItemForStrange;
    direction dir;
    int rowInSpace;
    int colInSpace;
    int capacity;
    
    bool gameLogicSolved;
    
    vector<Item*> inventory;
    
public:
    Character(string p_name, string p_conversation1, string p_conversation2,
              string p_conversation3, string p_key, string p_key2, direction p_dir, int p_capacity, int row, int col);
    virtual ~Character();
    string getName();
    int getRow();
    int getCol();
    bool getGameLogicSolved();
    
    direction getDirection();
    void setRow(int p_rowInSpace);
    void setCol(int p_colInSpace);
    void setDir(direction p_dir);
    void setGameLogicSolved(bool solved);
    
    void go(char move);
    virtual void addItem(Item* item);
    virtual void putBackItem(Item* item);
    virtual bool canPickMoreItem();
    virtual bool canPickItem(Item* item);
    virtual bool canGiveItem();
    virtual Item* giveOrPutOrUseItem();
    void displayInventory();
    void interact();
    
    friend std::ostream& operator<<(std::ostream& out, const Character& p_item);
    virtual std::ostream& print(std::ostream& out) const;
};

#endif /* Character_hpp */
