// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Tree class. All data
// members and functions of the class are defined here.
// *****************************************************************************
#include "Tree.hpp"

// *****************************************************************************
// Tree()
//
// This is the default constructor of a Tree.
// *****************************************************************************
Tree::Tree()
{
    display = 'T';
    walkable = false;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void Tree::interact()
{
    cout << "Hum, this tree is so tall!" << endl;
}
