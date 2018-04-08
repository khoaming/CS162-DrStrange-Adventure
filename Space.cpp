// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Space class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Space.hpp"

// *****************************************************************************
// Space(string p_name, int p_length, int p_width, char boundary)
//
// This is a constructor of a Space that sets its data members based on the
// parameters
// *****************************************************************************
Space::Space(string p_name, int p_length, int p_width, char boundary)
{
    name   = p_name;
    length = p_length;
    width  = p_width;
    
    north = east = south = west = NULL;
    fill(boundary);
}

// *****************************************************************************
// ~Space()
//
// This is the destructor of a Space. It frees dynamically allocated memory.
// *****************************************************************************
Space::~Space()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            delete area[i][j];
            area[i][j] = NULL;
        }
    }
}

// *****************************************************************************
// fill(char boundary)
//
// This function fills a Space with Squares. The boundaries are filled based on
// the parameter, while the rest are filled with Floors.
// *****************************************************************************
void Space::fill(char boundary)
{
    for (int i = 0; i < length; i++)
    {
        vector<Square*> row;
        for (int j = 0; j < width; j++)
        {
            Square* newSquare = NULL;
            
            if (i == 0 || j == 0 || i == length - 1 || j == width - 1)
            {
                switch (boundary)
                {
                    case 'w': newSquare = new Wall(); break;
                    case 't': newSquare = new Tree(); break;
                }
            }
            else
            {
                newSquare = new Floor();
            }
            row.push_back(newSquare);
        }
        area.push_back(row);
    }
}

string Space::getName()
{
    return name;
}

vector<vector<Square*>> Space::getArea()
{
    return area;
}

// *****************************************************************************
// setDestinationSpace(char direction, Space* destination)
//
// This function sets the destination of member portals based on parameters.
// *****************************************************************************
void Space::setDestinationSpace(char direction, Space* destination)
{
    switch (direction)
    {
        case 'n': north = destination; break;
        case 's': south = destination; break;
        case 'w': west  = destination; break;
        case 'e': east  = destination; break;
    }
}

// *****************************************************************************
// getDestinationSpace(char destination)
//
// This function returns a Spaces pointer that corresponds with the direction
// parameter of the this Space.
// *****************************************************************************
Space* Space::getDestinationSpace(char destination)
{
    switch (destination)
    {
        case 'n': return north; break;
        case 's': return south; break;
        case 'e': return east; break;
        case 'w': return west; break;
        default: return NULL;
    }
}

// *****************************************************************************
// getSquareInArea(int row, int col)
//
// This function returns s Squares pointer of the current Space at the given
// row and col.
// *****************************************************************************
Square* Space::getSquareInArea(int row, int col)
{
    return area[row][col];
}

// *****************************************************************************
// display()
//
// This function displays the current state of a Space. The << operator is
// overloaded in the Square class.
// *****************************************************************************
void Space::display()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << *area[i][j] << " ";
        }
        cout << endl;
    }
}

// *****************************************************************************
// insertCharacter(Character* Character)
//
// This function inserts a Character to the Space.
// *****************************************************************************
void Space::insertCharacter(Character* Character)
{
    area[Character->getRow()][Character->getCol()]->setCharacter(Character);
}

// *****************************************************************************
// insertItem(Item* item)
//
// This function inserts an Item to the Space.
// *****************************************************************************
void Space::insertItem(Item* item)
{
    area[item->getRow()][item->getCol()]->setItem(item);
}

// *****************************************************************************
// insertSquare(Square* special, int row, int col)
//
// This function inserts a special Square at the given row and col. This is used
// to insert portals.
// *****************************************************************************
void Space::insertSquare(Square* special, int row, int col)
{
    delete area[row][col];
    
    area[row][col] = special;
}

// *****************************************************************************
// insertSquare(char type, int row, int col)
//
// This function inserts a special Square at the given row and col. This is used
// to insert walls or fences depending on the parameter type.
// *****************************************************************************
void Space::insertSquare(char type, int row, int col)
{

    delete area[row][col];
    
    Square* newSquare = NULL;
    
    switch (type)
    {
        case 'w':
            newSquare = new Wall();
            break;
        case 'p':
            newSquare = new Portal();
            break;
        case 't':
            newSquare = new Tree();
            break;
        case 'f':
            newSquare = new Fence();
            break;
        case 'd':
            newSquare = new DarkMatter();
            break;
    }
    area[row][col] = newSquare;
}

// *****************************************************************************
// insertVerticalSquares(char type, int fromRow, int toRow, int col)
//
// This function inserts a vertical array of Squares depending on the type, to
// the specified locations.
// *****************************************************************************
void Space::insertVerticalSquares(char type, int fromRow, int toRow, int col)
{
    for (int row = fromRow; row <= toRow; row++)
    {
        insertSquare(type, row, col);
    }
}

// *****************************************************************************
// insertHorizontalSquares(char type, int fromCol, int toCol, int row)
//
// This function inserts a horizontal array of Squares depending on the type, to
// the specified locations.
// *****************************************************************************
void Space::insertHorizontalSquares(char type, int fromCol, int toCol, int row)
{
    for (int col = fromCol; col <= toCol; col++)
    {
        insertSquare(type, row, col);
    }
}

// *****************************************************************************
// moveCharacter(Space*& current, Character* character, char move)
//
// This function moves a Character (Strange) in the current Space that the
// Character is on, depending on the move specified by the user.
// *****************************************************************************
void Space::moveCharacter(Space*& current, Character* character, char move)
{
    int characterRow = character->getRow();
    int characterCol = character->getCol();
    area[characterRow][characterCol]->setCharacter(NULL);
    
    switch (move)
    {
        case 'a': character->setDir(WEST) ; characterCol--; break;
        case 'd': character->setDir(EAST) ; characterCol++; break;
        case 'w': character->setDir(NORTH); characterRow--; break;
        case 's': character->setDir(SOUTH); characterRow++; break;
    }
    
    // get what is at the location where the Character will be moving to
    char display = area[characterRow][characterCol]->getDisplay();
    
    // check if the Character is flying, the Square is walkable, or already has
    // another character
    bool flying = dynamic_cast<DrStrange*>(character)->getFlying();
    bool walkable = area[characterRow][characterCol]->getWalkable();
    bool hasChar = area[characterRow][characterCol]->hasCharacter();

    // if not valid move, restores the current location
    if (!(walkable || ((display != 'T') && (display != '#') && flying && !hasChar)))
    {
        characterRow = character->getRow();
        characterCol = character->getCol();
    }
    
    // if the location is a portal, change the current location to the Space
    // which the portal is pointing to. Also, adjust the Character's location
    // to match the location of the connected portal of the destination Space
    if (area[characterRow][characterCol]->getIsPortal())
    {
        char destination = dynamic_cast<Portal*>(area[characterRow][characterCol])->getDestination();
        int temp = 0;
        temp = dynamic_cast<Portal*>(area[characterRow][characterCol])->getDestRow();
        characterCol = dynamic_cast<Portal*>(area[characterRow][characterCol])->getDestCol();
        characterRow = temp;
        
        current = current->getDestinationSpace(destination);
        cout << "Entering " << current->getName() << endl;
    }
    
    // set location
    character->setRow(characterRow);
    character->setCol(characterCol);
    
    // set Character on the current Space and display the updated Space.
    (current->getArea())[characterRow][characterCol]->setCharacter(character);
    current->display();
}
