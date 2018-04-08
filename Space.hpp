// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Space class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Square.hpp"
#include "Floor.hpp"
#include "Wall.hpp"
#include "Fence.hpp"
#include "Portal.hpp"
#include "Tree.hpp"
#include "DarkMatter.hpp"
#include "DrStrange.hpp"
#include "Item.hpp"
#include "Utilities.hpp"
#include <vector>
using std::vector;

class Space
{
protected:
    string name;
    int length;
    int width;
    
    vector<vector<Square*>> area;
    
    Space* north;
    Space* east;
    Space* south;
    Space* west;
    
public:
    
    Space(string p_name, int p_length, int p_width, char boundary);
    virtual ~Space();
    
    // initializing functions
    void fill(char boundary);
    void insertSquare(Square* special, int row, int col);
    void insertSquare(char type, int row, int col);
    void insertVerticalSquares(char type, int fromRow, int toRow, int col);
    void insertHorizontalSquares(char type, int fromCol, int toCol, int row);
    void insertCharacter(Character* character);
    void insertItem(Item* item);
    void setDestinationSpace(char direction, Space* destination);

    // getter functions
    string getName();
    Square* getSquareInArea(int row, int col);
    Space* getDestinationSpace(char destination);
    vector<vector<Square*>> getArea();
    
    // support functions
    void display();
    void moveCharacter(Space*& current, Character* character, char move);
    
    // to make this an abstract class
    virtual void whereIsThis() = 0;
};


#endif
