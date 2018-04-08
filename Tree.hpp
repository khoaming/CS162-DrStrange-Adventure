// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Tree class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef TREE_HPP
#define TREE_HPP

#include "Square.hpp"


// *****************************************************************************
// Tree()
//
// This is the default constructor of a Tree.
// *****************************************************************************
class Tree : public Square
{
public:
    Tree();
    void interact();
};

#endif 
