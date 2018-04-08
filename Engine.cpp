// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of the Engine class. All data
// members and functions of the class are defined here.
// *****************************************************************************

#include "Engine.hpp"

// *****************************************************************************
// Engine()
//
// This is the default constructor of an Engine.
// *****************************************************************************
Engine::Engine()
{
    time = 500; // time limit
    
    Strange = new DrStrange("Stephen Strange","", "", "",
                            "Sorcerer Supreme Certification",
                            "Grade A for CS 162!", EAST, 10, 1, 1);
    
    // create spaces with specified length, width, and boundary
    Kathmandu = new City("Kathmandu", 11, 19, 't');
    KamarTaj = new Building("Kamar-Taj", 11, 15, 'w');
    Library = new Room("Mystic Arts Library", 11, 19, 'w');
    SecretRoom = new Room("Masters' Secret Room", 15, 19, 'w');
    NewYorkSanctum = new Building("New York Sanctum", 15, 11, 'w');
    HongKong = new City("Hong Kong", 15, 19, 't');
    
    // set up spaces to initial state
    setKamarTaj();
    setKathmandu();
    setLibrary();
    setSecretRoom();
    setNewYorkSanctum();
    setHongKong();
}

// *****************************************************************************
// ~Engine()
//
// This is the destructor of a Engine. It frees dynamically allocated memory.
// *****************************************************************************
Engine::~Engine()
{
    delete Kathmandu;
    delete KamarTaj;
    delete Library;
    delete SecretRoom;
    delete NewYorkSanctum;
    delete HongKong;
    // delete Strange; // would have been deleted in Hong Kong
}

// *****************************************************************************
// setKathmandu()
//
// Thiss set up Kathmandu to its initial state.
// *****************************************************************************
void Engine::setKathmandu()
{
    
    Kathmandu->insertVerticalSquares('f', 4, 6, 3);
    Kathmandu->insertVerticalSquares('f', 4, 6, 9);
    Kathmandu->insertVerticalSquares('f', 4, 6, 15);
    Kathmandu->insertHorizontalSquares('f', 4, 14, 7);
    Kathmandu->insertHorizontalSquares('f', 4, 14, 3);
    
    Kathmandu->setDestinationSpace('n', KamarTaj);
    Portal* portal1 = new Portal('n', false, false, "Kamar-Taj Mysterious Sequence", 5, 12);
    Kathmandu->insertSquare(portal1, 5, 12);
    
    Character* Mordo = new Character("Mordo","Hi there, I am missing my watch, can you help me find it?", "Congratulations! You have proven to be an honest man and thus is worthy to go to Kamar-Taj, just as you wish! Here, take this!", "Hey again, how are you?", "Golden Rolex", "Kamar-Taj Mysterious Sequence", WEST, 2, 5, 14);
    Kathmandu->insertCharacter(Mordo);
    
    Item* ladder1 = new Item("Wooden Ladder", "This is a short ladder that can help climb up low things!", '|', true, 5, 3);
    Kathmandu->insertItem(ladder1);
    
    Item* rolex = new Item("Golden Rolex", "This is a nice watch, I wonder to whom it belongs.", '@', true, 5, 6);
    Kathmandu->insertItem(rolex);
    
    Item* karmaTajSequence = new Item("Kamar-Taj Mysterious Sequence", "One who has this mystical sequence, shall be able to unlock the portal it protects!", 'x', true, 0, 0);
    Mordo->addItem(karmaTajSequence);

}

// *****************************************************************************
// setKamarTaj()
//
// This sets up KamarTaj to its initial state.
// *****************************************************************************
void Engine::setKamarTaj()
{
    KamarTaj->setDestinationSpace('s', Kathmandu);
    KamarTaj->setDestinationSpace('e', Library);
    Portal* portal1 = new Portal('s', false, true, "", 5, 12);
    KamarTaj->insertSquare(portal1, 5, 12);
    Portal* portal2 = new Portal('e', false, false, "Library Mysterious Sequence", 5, 3);
    KamarTaj->insertSquare(portal2, 5, 2);
    
    KamarTaj->insertHorizontalSquares('f', 1, 14, 3);
    KamarTaj->insertHorizontalSquares('f', 1, 14, 7);
    
    Item* ladder1 = new Item("Wooden Ladder", "This is a short ladder that can help climb up low things!", '|', true, 4, 7);
    KamarTaj->insertItem(ladder1);
    Item* ladder2 = new Item("Wooden Ladder", "This is a short ladder that can help climb up low things!", '|', true, 6, 7);
    KamarTaj->insertItem(ladder2);
    
    Character* Mordo = new Character("Mordo","Welcome to Kamar-Taj, I am Master Mordo. You should forget everything you think you know before the Ancient One can teach you mystical arts!", "Ok I made you Forgetting Tea and you drank it! I certify that you forgot things now. Give this certificate to Ancient One and she shall teach you!", "Hey again, have you seen the Ancient One?", "Forgetting Powder", "Certification of Humility", WEST, 2, 5, 10);
    KamarTaj->insertCharacter(Mordo);
    
    Character* Person1 = new Character("A Person","Welcome to Kamar-Taj, I know what you need, give me a ladder so I can take it for you.", "Here you go, I am glad I didn't fall off the flimsy ladder!", "Hey again, have you seen the Ancient One?", "Wooden Ladder", "Forgetting Powder", SOUTH, 2, 1, 7);
    KamarTaj->insertCharacter(Person1);
    
    Character* Person2 = new Character("A Person","Welcome to Kamar-Taj, I know what you need, give Mordo his powder and he can make some tea for you!", "", "Hey again, have you seen the Ancient One?", "", "", EAST, 2, 5, 4);
    KamarTaj->insertCharacter(Person2);
    
    Character* AncientOne = new Character("Ancient One","Welcome to Kamar-Taj, I know what you need, give Mordo his powder and he can make some tea for you!", "I am the Ancient One! I have been watching you! Welcome to the multiverse and endless possibilities! Here is your mystical key to our mystic arts library. Learn fast, dark days are imminent!", "Hey again, how are you doing with your trainings?", "Certification of Humility", "Library Mysterious Sequence", NORTH, 2, 9, 7);
    KamarTaj->insertCharacter(AncientOne);
    
    Item* powder = new Item("Forgetting Powder", "This powder is the critical ingredient to make Forgetting Tea.", 'P', true, 8, 8);
    Person1->addItem(powder);
    
    Item* certificate = new Item("Certification of Humility", "One who has this certification, shall give it to the Ancient One to begin mystic arts training!", 'C', true, 0, 0);
    Mordo->addItem(certificate);

    Item* librarySequence = new Item("Library Mysterious Sequence", "One who has this mystical sequence, shall be able to unlock the portal it protects!", 'x', true, 0, 0);
    AncientOne->addItem(librarySequence);
    
}

// *****************************************************************************
// setLibrary()
//
// This sets up Library to its initial state.
// *****************************************************************************
void Engine::setLibrary()
{
    Library->setDestinationSpace('w', KamarTaj);
    Library->setDestinationSpace('s', SecretRoom);
    Library->insertVerticalSquares('w', 1, 9, 1);
    Library->insertVerticalSquares('w', 1, 9, 17); // to hide the hidden portal and prevent out of bound move
    
    Portal* portal1 = new Portal('w', false, true, "", 5, 2); // hiddened but fully opened
    Library->insertSquare(portal1, 5, 3);
    Portal* portal2 = new Portal('s', true, true, "", 7, 16);
    Library->insertSquare(portal2, 5, 17);
    
    
    Character* Wong = new Character("Wong","Welcome to the Mystical Arts Library, I am Wong - keeper of the library! First, find me my favorite CD and I will give you the key to endless knowledge!", "You know me well buddy! Here is the direction to our sacred section for Masters! Good luck with what is ahead of you!", "Go! Quickly! This planet will depend on you!", "Lady Gaga CD", "Direction to Secret Room", WEST, 2, 5, 7);
    Library->insertCharacter(Wong);
    
    Item* cd1 = new Item("Lady Gaga CD", "This CD has Poker Face song on it, must be from Lady Gaga.", '0', true, 3, 9);
    Library->insertItem(cd1);
    
    Item* cd2 = new Item("Justin Bieber CD", "This CD has Love Yourself song on it, must be from Justin Bieber.", '0', true, 5, 9);
    Library->insertItem(cd2);
    
    Item* cd3 = new Item("Selena Gomez CD", "This CD has Good For You song on it, must be from Selena Gomez.", '0', true, 7, 9);
    Library->insertItem(cd3);
    
    Item* picture1 = new Item("Mystical Picture", "Nice picture! This looks like a building in London!", '{', true, 4, 16);
    Library->insertItem(picture1);
    Item* picture2 = new Item("Mystical Picture", "Nice picture! This looks like a building in Hong Kong!", '{', true, 5, 16);
    Library->insertItem(picture2);
    Item* picture3 = new Item("Mystical Picture", "Nice picture! This looks like a building in New York!", '{', true, 6, 16);
    Library->insertItem(picture3);
    
    Item* directionNote = new Item("Direction to Secret Room", "Behind the Hong Kong sanctum lies the path to a mystical remnant of the multiverse!", '!', true, 0, 0);
    Wong->addItem(directionNote);
    
}

// *****************************************************************************
// setSecretRoom()
//
// This sets up SecretRoon to its initial state.
// *****************************************************************************
void Engine::setSecretRoom()
{
    SecretRoom->setDestinationSpace('n', Library);
    SecretRoom->setDestinationSpace('s', HongKong);
    SecretRoom->setDestinationSpace('e', NewYorkSanctum);
    SecretRoom->setDestinationSpace('w', Kathmandu);
    Portal* portal1 = new Portal('n', false, true, "", 5, 17);
    SecretRoom->insertSquare(portal1, 7, 16);
    Portal* portal2 = new Portal('s', false, false, "Hong Kong Mystical Sequence", 6, 4);
    SecretRoom->insertSquare(portal2, 7, 2);
    Portal* portal3 = new Portal('e', false, true, "", 12, 5);
    SecretRoom->insertSquare(portal3, 2, 9);
    Portal* portal4 = new Portal('w', false, true, "", 5, 12);
    SecretRoom->insertSquare(portal4, 12, 9);
    
    SecretRoom->insertVerticalSquares('f', 4, 10, 8);
    SecretRoom->insertVerticalSquares('f', 4, 10, 10);
    SecretRoom->insertHorizontalSquares('f', 6, 12, 6);
    SecretRoom->insertHorizontalSquares('f', 6, 12, 8);
    
    Item* eyeOfAgamotto = new Item("Eye of Agamotto","One who has this infinity gem, shall have the ability to bend time!",'*', true, 7, 9);
    SecretRoom->insertItem(eyeOfAgamotto);
}

// *****************************************************************************
// setNewYorkSanctum()
//
// This sets up NewYorkSanctum to its initial state.
// *****************************************************************************
void Engine::setNewYorkSanctum()
{
    NewYorkSanctum->setDestinationSpace('w', SecretRoom);
    Portal* portal1 = new Portal('w', false, true, "", 2, 9);
    NewYorkSanctum->insertSquare(portal1, 12, 5);
    
    NewYorkSanctum->insertVerticalSquares('w', 4, 10, 2);
    NewYorkSanctum->insertVerticalSquares('w', 4, 10, 4);
    NewYorkSanctum->insertVerticalSquares('w', 4, 10, 6);
    NewYorkSanctum->insertVerticalSquares('w', 4, 10, 8);
    
    Character* Kaecilius = new Character("Kaecilius","You are too late Strange! I, Kaecilius, now has taken the Cloak of Levitation! Dormmamu will appreciate this tribute!", "W.h..a.t...d..i.d..yo...u...d..o..to..m...e?!", "G..r.u...G..r.u...!", "Crimson Bands of Cyttorak", "Cloak of Levitation", SOUTH, 2, 2, 5);
    NewYorkSanctum->insertCharacter(Kaecilius);
    
    Item* cloak = new Item("Cloak of Levitation","One who wears this mystical artifact, shall have the ability to fly!",')', true, 0, 0);
    Kaecilius->addItem(cloak);
    
    Item* hongKongSequence = new Item("Hong Kong Mystical Sequence","One who has this mystical sequence, shall be able to unlock the portal it protects!",'x', true, 7, 5);
    NewYorkSanctum->insertItem(hongKongSequence);
    
    Item* crimson = new Item("Crimson Bands of Cyttorak","One who uses this mystical artifact to trap someone, shall trap the person forever!",'&', true, 7, 3);
    NewYorkSanctum->insertItem(crimson);
    
    Item* vase = new Item("Mystical Vase","One who has this mystical vase, shall appreciate the beauty of it!",'?', true, 7, 7);
    NewYorkSanctum->insertItem(vase);
    
}

// *****************************************************************************
// setHongKong()
//
// This sets up HongKong to its initial state.
// *****************************************************************************
void Engine::setHongKong()
{
    HongKong->setDestinationSpace('n', SecretRoom);
    Portal* portal1 = new Portal('n', false, true, "", 7, 2);
    HongKong->insertSquare(portal1, 6, 4);

    HongKong->insertVerticalSquares('d', 1, 13, 8);
    HongKong->insertVerticalSquares('d', 1, 13, 9);
    HongKong->insertVerticalSquares('d', 1, 13, 10);
    HongKong->insertVerticalSquares('d', 1, 13, 11);
    HongKong->insertVerticalSquares('d', 1, 13, 12);
    HongKong->insertVerticalSquares('d', 1, 13, 13);
    HongKong->insertVerticalSquares('d', 1, 13, 14);
    HongKong->insertVerticalSquares('d', 1, 13, 15);
    HongKong->insertVerticalSquares('d', 1, 13, 16);
    HongKong->insertVerticalSquares('d', 1, 13, 17);

    Character* Dormammu = new Character("Dormammu","I am Dormammu, Lord of the Dark Dimension, aka Worlds Destroyer. This world is mine now! I am telling you, nothing can make me more HAPPY than devouring this planet! If you give me something that can make me more HAPPY, I can rethink about devouring this tiny planet of yours!", "What mystical substance is this? It made me feel so HAPPY! Here you go, I certify you as the Sorcerer Supreme of this planet! Bring me more beer next time!", "Any more beer?", "Beer", "Sorcerer Supreme Certification", WEST, 2, 7, 15);
    HongKong->insertCharacter(Dormammu);
    
    Item* donut = new Item("Donut","One who devours this, shall feel more SATISFIED than ever before!",'D', true, 4, 4);
    HongKong->insertItem(donut);
    
    Item* beer = new Item("Beer","One who bottoms up this, shall feel more HAPPY than ever before!",'B', true, 7, 7);
    HongKong->insertItem(beer);
    
    Item* project = new Item("Completed Final Project","One who has this, shall feel more ACCOMPLISHED than ever before!",'P', true, 8, 4);
    HongKong->insertItem(project);
    
    Item* energyDrink = new Item("Energy Drink","One who consumes this, shall feel more ENERGETIC than ever before!",'E', true, 10, 4);
    HongKong->insertItem(energyDrink);
    
    Item* certificate = new Item("Sorcerer Supreme Certification","One who has this title, shall bear the responsibility of protecting this planet from mystical threats!",'/', true, 0, 0);
    Dormammu->addItem(certificate);
}

// *****************************************************************************
// getFrontSquare()
//
// This returns the square that is in front of Strange.
// *****************************************************************************
Square* Engine::getFrontSquare()
{
    int frontRow = Strange->getRow();
    int frontCol = Strange->getCol();
    
    direction facing = Strange->getDirection();
    
    switch (facing)
    {
        case NORTH: frontRow--; break;
        case SOUTH: frontRow++; break;
        case WEST:  frontCol--; break;
        case EAST:  frontCol++; break;
    }
    return currentSpace->getSquareInArea(frontRow, frontCol);
}

// *****************************************************************************
// strangeChecksSquare()
//
// This function is allows Strange to check the Square that is in front of him.
// *****************************************************************************
void Engine::strangeChecksSquare()
{
    currentSpace->display();
    
    Square* front = getFrontSquare();
    
    if (front->hasCharacter())
    {
        strangeInteracts(front);
    }
    else if (front->hasItem())
    {
        strangeChecksItem(front);
    }
    else
    {
        front->interact();
    }
}

// *****************************************************************************
// strangeInteracts(Square* front)
//
// This function is allows Strange to interact with the character that is in
// front of him.
// *****************************************************************************
void Engine::strangeInteracts(Square* front)
{
    
    
    if (front->hasCharacter())
    {
        direction facing = Strange->getDirection();
        Character* other = front->getCharacter();
        
        // to make the other character face Strange
        switch (facing)
        {
            case NORTH: other->setDir(SOUTH); break;
            case SOUTH: other->setDir(NORTH); break;
            case WEST:  other->setDir(EAST) ; break;
            case EAST:  other->setDir(WEST) ; break;
        }
        // to clear terminal screen
        // CREDIT: Michael Nameoff example file
        cout << "\033[2J\033[1;1H";
        currentSpace->display();
        
        other->interact();
    }
    else
    {
        cout << "This is strange, thought I saw someone..." << endl;
    }
}

// *****************************************************************************
// strangeChecksItem(Square* front)
//
// This function is allows Strange to interact with the item that is in front
// of him.
// *****************************************************************************
void Engine::strangeChecksItem(Square* front)
{
    if (front->hasItem())
    {
        front->getItem()->interact();
    }
    else
    {
        cout << "This is strange, thought I saw something..." << endl;
    }
    
}

// *****************************************************************************
// strangePicksItem()
//
// This function is allows Strange to pick the item that is in front of him.
// *****************************************************************************
void Engine::strangePicksItem()
{
    currentSpace->display();
    
    Square* front = getFrontSquare();
    
    if (front->hasItem())
    {
        if (Strange->canPickMoreItem())
        {
            if (front->getItem()->getCanBePickedUp())
            {
                // to clear terminal screen
                // CREDIT: Michael Nameoff example file
                cout << "\033[2J\033[1;1H";
                
                Item * temp = front->getItem();
                front->setItem(NULL);
                
                currentSpace->display(); // has to be here to display correctly
                
                Strange->addItem(temp);
            }
            else
            {
                // to clear terminal screen
                // CREDIT: Michael Nameoff example file
                cout << "\033[2J\033[1;1H";
                currentSpace->display();
                cout << "What magic is this?! I can't even budge this!" << endl;
            }
        }
    }
    else
    {
        // to clear terminal screen
        // CREDIT: Michael Nameoff example file
        cout << "\033[2J\033[1;1H";
        currentSpace->display();
        cout << "This is strange, thought I saw something..." << endl;
    }
}

// *****************************************************************************
// strangePutsItem()
//
// This function is allows Strange to put an item to a Square that is in front
// of him.
// *****************************************************************************
void Engine::strangePutsItem()
{
    Square* front = getFrontSquare();
    front->setItem(Strange->giveOrPutOrUseItem());
    currentSpace->display();
}

// *****************************************************************************
// strangeUsesItemOnSomethingInFront()
//
// This function is allows Strange to put an item to a Square, or give it to a
// character, or apply it to a portal that is in front of him.
// *****************************************************************************
void Engine::strangeUsesItemOnSomethingInFront()
{
    currentSpace->display();
    
    Square* front = getFrontSquare();
    
    if (front->getIsPortal())
    {
        Item* used = Strange->giveOrPutOrUseItem();  // have to change this to dr strange
        
        if (used != NULL)
        {
            // has to dynamic_cast so it becomes a Portal pointer
            if (dynamic_cast<Portal*>(front)->getOpenSpell() == used->getName())
            {
                dynamic_cast<Portal*>(front)->setFullyOpened(true);
                
                delete used;
                // to clear terminal screen
                // CREDIT: Michael Nameoff example file
                cout << "\033[2J\033[1;1H";
                currentSpace->display();
                dynamic_cast<Portal*>(front)->interact();
            }
            else
            {
                cout << "Hum a mysterious voice from the portal is telling me that it doesn't like this item!" << endl;
                Strange->putBackItem(used);
            }
        }
    }
    else if (front->hasCharacter())
    {
        Character* other = front->getCharacter();
        Item* used = Strange->giveOrPutOrUseItem();
        bool givenItem = false;
        
        if (used != NULL) // in case user chose 'Naahh'
        {
            if (other->canPickMoreItem() && other->canPickItem(used))
            {
                // to clear terminal screen
                // CREDIT: Michael Nameoff example file
                cout << "\033[2J\033[1;1H";
                currentSpace->display();
                other->addItem(used);
                givenItem = true;
            }
            else
            {
                Strange->putBackItem(used);
            }
        }
        
        // if the item satisfy a character's game logic, the character gives an
        // important item for game logic to Strange.
        if (givenItem && other->getGameLogicSolved())
        {
            strangeInteracts(front);
            
            if (other->canGiveItem())
            {
                Strange->addItem(other->giveOrPutOrUseItem());
            }
        }
    }
    else
    {
        if (!front->hasItem())
        {
            Item* used = Strange->giveOrPutOrUseItem();  // have to change this to dr strange
            
            if (used != NULL)
            {
                front->setItem(used);
                // to clear terminal screen
                // CREDIT: Michael Nameoff example file
                cout << "\033[2J\033[1;1H";
                currentSpace->display();
            }
        }
        else
        {
            // to clear terminal screen
            // CREDIT: Michael Nameoff example file
            cout << "\033[2J\033[1;1H";
            currentSpace->display();
            cout << "Hum a mysterious voice is telling me that I cannot put anything in front!" << endl;
        }
    }
}

// *****************************************************************************
// strangeUsesItem()
//
// This function is allows Strange to use an item on himself if that item can
// be used. Except for the Cloak of Levitation, other items should just print
// out fun conversations (see DrStrange class useItem() for more details).
// *****************************************************************************
void Engine::strangeUsesItem()
{
    currentSpace->display();
    Strange->useItem();
}

// *****************************************************************************
// strangeChecksInventory()
//
// This function displays the inventory of Strange.
// *****************************************************************************
void Engine::strangeChecksInventory()
{
    currentSpace->display();
    Strange->displayInventory();
}

// *****************************************************************************
// strangeChecksLocation()
//
// This function displays information about the current location.
// *****************************************************************************
void Engine::strangeChecksLocation()
{
    currentSpace->display();
    currentSpace->whereIsThis();
}

// *****************************************************************************
// play()
//
// This function is the driver function of the Engine that will execute actions
// based on user's input. It will keep prompting user for the next action until
// time runs out (each action takes one time unit), the game is won, or user
// chooses to exit.
// *****************************************************************************
void Engine::play()
{
    currentSpace = Kathmandu; // where the game will start
    currentSpace->insertCharacter(Strange);
    char action = ' ';
    
    currentSpace->display();
    
    do
    {

        cout << "Time: " << time-- << endl;

        help();
        
        action = getChar("What should I do now: ");
        
        // to clear terminal screen
        // CREDIT: Michael Nameoff example file
        cout << "\033[2J\033[1;1H";
        
        switch (action)
        {
            case 'a':
            case 's':
            case 'd':
            case 'w': currentSpace->moveCharacter(currentSpace, Strange, action); break;
            case 'p': strangePicksItem(); break;
            case 'i': strangeChecksInventory(); break;
            case 'c': strangeChecksSquare(); break;
            case 'g': strangeUsesItemOnSomethingInFront(); break;
            case 'u': strangeUsesItem(); break;
            case 'l': strangeChecksLocation(); break;
            default: break;
        }
        
        // confirm before exiting
        if (action == 'x')
        {
            action = getCharYesNo("Exit game (y/n)?: ");
            if (action == 'y')
            {
                action = 'x';
            }
            else
            {
                action = 'n';
            }
        }
        
    } while (action!= 'x' && time > 0 && !Strange->getGameLogicSolved());
    
    // print result if won
    if (Strange->getGameLogicSolved())
    {
        cout << "Great job! You saved the world and earned Khoa an A grade for CS 162!" << endl;
    }
}
