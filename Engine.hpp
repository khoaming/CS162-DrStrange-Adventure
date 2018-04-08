// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file of the Engine class. All data members
// and functions of the class are declared here.
// *****************************************************************************

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "DrStrange.hpp"
#include "City.hpp"
#include "Building.hpp"
#include "Room.hpp"
#include "Portal.hpp"
#include "DrStrange.hpp"
#include "Item.hpp"
#include "Utilities.hpp"

class Engine
{
private:
    
    int time;
    
    Space* Kathmandu;
    Space* KamarTaj;
    Space* Library;
    Space* SecretRoom;
    Space* NewYorkSanctum;
    Space* HongKong;
    
    Space* currentSpace;
    DrStrange* Strange;
    
    
public:
    Engine();
    ~Engine();
    
    // initializing functions
    void setKathmandu();
    void setKamarTaj();
    void setLibrary();
    void setSecretRoom();
    void setNewYorkSanctum();
    void setHongKong();
    
    // support functions
    Square* getFrontSquare();
    void strangeChecksSquare();
    void strangePicksItem();
    void strangeInteracts(Square* front);
    void strangeChecksItem(Square* front);
    void strangeUsesItemOnSomethingInFront();
    void strangeChecksInventory();
    void strangeUsesItem();
    void strangePutsItem();
    void strangeChecksLocation();
    
    // driver function
    void play();
    
};


#endif /* Engine_hpp */
