// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Fence class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Fence.hpp"


// *****************************************************************************
// Fence()
//
// This is the default constructor of a Fence.
// *****************************************************************************
Fence::Fence()
{
    display = 'Y';
    walkable = false;
}

// *****************************************************************************
// interact()
//
// This function overides the pure virtual function of the Square base class.
// It display a conversation line when Strange checks what is in front.
// *****************************************************************************
void Fence::interact()
{
    cout << "Hah this fence is not too tall to climb over with a ladder!" << endl;
}
