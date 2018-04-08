// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the DrStrange class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "DrStrange.hpp"

// *****************************************************************************
// DrStrange(string p_name, string p_conversation1, string p_conversation2,
// string p_conversation3, string p_key, string p_key2, direction p_dir,
// int row, int col, int p_capacity)
//
// This is a constructor of a DrStrange that sets up its data members based on the
// parameters. The flying data member is defaulted to be false.
// *****************************************************************************
DrStrange::DrStrange(string p_name, string p_conversation1, string p_conversation2,
                 string p_conversation3, string p_key, string p_key2, direction p_dir,
                     int row, int col, int p_capacity)
: Character(p_name, p_conversation1, p_conversation2, p_conversation3,
            p_key, p_key2, p_dir, row, col, p_capacity)
{
    flying = false;
}

bool DrStrange::getFlying()
{
    return flying;
}

// *****************************************************************************
// canPickMoreItem()
//
// This function returns a boolean to indicate whether Strange can pick more
// item depending on his inventory's capacity.
// *****************************************************************************
bool DrStrange::canPickMoreItem()
{
    bool can = ((signed)inventory.size() < capacity);
    
    if (!can)
    {
        cout << "Hum my backpack is full, got to free some space!" << endl;
    }
    
    return can;
}

// *****************************************************************************
// addItem(Item* item)
//
// This function allows Strange to add an item to inventory. This will also
// set the gameLogicSolved to true if Strange has received the key item to win
// the game.
// *****************************************************************************
void DrStrange::addItem(Item* item)
{
    inventory.push_back(item);
    
    cout << "You got a " << item->getName() << "!" << endl;
    
    if (item->getName() == keyToSolveGameLogic)
    {
        gameLogicSolved = true;
    }
}

// *****************************************************************************
// giveOrPutOrUseItem()
//
// This function allows the user to choose which item to give or put or use to
// whatever is in front of Strange.
// *****************************************************************************
Item* DrStrange::giveOrPutOrUseItem()
{
    if (inventory.size() == 0)
    {
        cout << "Nothing is in your backpack!" << endl;
        return NULL;
    }
    else
    {
        cout << "0 - Nah" << endl;
        displayInventory();

        int choice = getInt("Which item? ", EQ_GREATER, 0, AND, EQ_SMALLER, (unsigned) inventory.size());

        if (choice == 0)
        {
            return NULL;
        }
        else
        {
            Item* toUse = inventory[choice - 1]; // -1 to match index

            inventory.erase(inventory.begin() + choice - 1);
            
            return toUse;
        }
    }
}

// *****************************************************************************
// useItem()
//
// This function allows the user to choose what item Strange will use on himself.
// When he uses the Cloak of Levitation, he will fly and can go through Dark
// Matter. For the other items, there will be some hopefully fun conversations.
// *****************************************************************************
void DrStrange::useItem()
{
    
    if (inventory.size() == 0)
    {
        cout << "Nothing is in your backpack!" << endl;
    }
    else
    {
        cout << "0 - Naahhh" << endl;
        
        displayInventory();
        
        int choice = getInt("Which item? ", EQ_GREATER, 0, AND, EQ_SMALLER, (unsigned) inventory.size());
        
        string usedItem = "";
        
        if (choice != 0) // user chose something
        {
            usedItem = inventory[choice - 1]->getName(); // -1 to match index
            
            if (usedItem == "Cloak of Levitation")
            {
                flying = true;
                cout << "Hey look! I am flying!" << endl;
            }
            else if (usedItem == "Eye of Agamotto")
            {
                cout << "Hah, time is under my control now!" << endl;
            }
            else if (usedItem == "Beer")
            {
                cout << "Nice taste, but I got to stay awake to save the world!" << endl;
            }
            else if (usedItem == "Wooden Ladder")
            {
                cout << "Are you putting a ladder on yourself? That is strange..." << endl;
            }
            else if (usedItem == "Golden Rolex")
            {
                cout << "Catchy watch! But whoever lost it must be so sad!" << endl;
            }
            else if (usedItem == "Forgetting Powder")
            {
                cout << "Hum I don't know how to make tea out of this!" << endl;
            }
            else if (usedItem == "Completed Final Project")
            {
                cout << "Whoever finished this project must be feeling so relieved!" << endl;
            }
            else if (usedItem == "Energy Drink")
            {
                cout << "Wow, this is what I need right now!" << endl;
            }
            else if (usedItem == "Donut")
            {
                cout << "Strange, you should be on diet!" << endl;
            }
            else if (usedItem == "Crimson Bands of Cyttorak")
            {
                cout << "Strange, do you want to be trapped forever?!" << endl;
            }
            else if ((usedItem == "Lady Gaga CD") || (usedItem == "Justin Bieber CD") || (usedItem == "Selena Gomez CD"))
            {
                cout << "Strange, are you playing this CD by your mouth?!" << endl;
            }
            else
            {
                cout << "Hum..nothing happened. But why would you need to use this, Strange?!" << endl;
            }
        }
    }
}
