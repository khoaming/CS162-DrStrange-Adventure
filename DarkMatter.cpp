// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the DarkMatter class. All data
// members and functions of the class are defined here.
// *****************************************************************************
#include "DarkMatter.hpp"


// *****************************************************************************
// DarkMatter()
//
// This is the default constructor of a DarkMatter.
// *****************************************************************************
DarkMatter::DarkMatter()
{
    display = '~';
    walkable = false;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void DarkMatter::interact()
{
    cout << "This looks like Dark Matter of the Dark Dimension. I need to fly to traverse it!" << endl;
}
