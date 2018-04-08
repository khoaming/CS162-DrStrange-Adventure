// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the implementation file of all utility functions.
// *****************************************************************************

#include "Utilities.hpp"


// *****************************************************************************
// help()
//
// This function will print out a menu containing options that a user can choose
// from when playing the game.
// *****************************************************************************
void help()
{
    cout << endl;
    cout << "######################  Menu #####################" << endl;
    cout << "#                                                #" << endl;
    cout << "#      w - move forward                          #" << endl;
    cout << "#      s - move backward;                        #" << endl;
    cout << "#      a - move left                             #" << endl;
    cout << "#      d - move right                            #" << endl;
    cout << "#      l - check location                        #" << endl;
    cout << "#      c - check front                           #" << endl;
    cout << "#      i - display inventory                     #" << endl;
    cout << "#      p - pick item in front                    #" << endl;
    cout << "#      u - use item on self                      #" << endl;
    cout << "#      g - give / put / apply item to front      #" << endl;
    cout << "#      x - exit game                             #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << endl;
}

// *****************************************************************************
// printIntro
//
// This function prints the introduction to a program.
// *****************************************************************************
void printIntro()
{
    cout << endl;
    cout << "Doctor Strange Silly Adventure - by Khoa Nguyen\n"                                       << endl;
    cout << "Hello Stephen Strange, your objective is to gain the 'Sorcerer Supreme Certification' before Earth is devoured!"  << endl;
    cout << "Good luck and have fun!"                                                                 << endl;
    cout << endl;
}

// *****************************************************************************
// getInt
//
// This function takes a string prompt (required) and five optional ints
// representing the operators and values to perform input validation as
// parameters. These five optional parameters are default to 0. It will call
// the printPrompt function to dynamically print out the prompt for user
// depending on the requirement for additional input validations. It will then
// ensure that the user has entered only an integer. If the input is indeed
// an integer, it will validate if the integer entered passes additional
// validations (the range of the integer). If the input is not an int or an
// out-of-range int, it will let the user know so they can enter another value.
// When everything is validated, it will return the int that the user has input.
//
// Example function calls:
//
// Ex1: getInt("Number of steps ");
// This will prompt the user for an int and make sure that they only enter an
// int without any further validations.
//
//
// Ex2: getInt("Number of steps ", GREATER, 0);
// This will prompt the user for an int and make sure that they only enter an
// int AND validate if the int is greater than 0.
//
// Ex3: getInt("Number of rows for the grid ", EQ_GREATER, 2, AND, EQ_SMALLER, 50);
// This will prompt the user for an int and make sure that they only enter an
// int AND validate if the int is >= 2 and <= 50 (in the range [2, 50]
// inclusive).
//
// CREDIT: I got the idea for the integer validation part of this function
// through the following link:
//
// http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
//
// This was the best implementation for integer input validation I found as it
// was simple to understand and performed correctly as intended in the cases
// the user inputs: a double (2.0), an int followed by a character (1a), a
// character (a), a character followed by an int (a1), etc.. that other
// implementations fail to validate.
// *****************************************************************************
int getInt(string prompt, int oper_1, int value_1,
           int logic, int oper_2, int value_2)
{
    int userInput;
    bool valid = false;
    
    cout << prompt << "(an int";
    // dynamically print the prompt
    printPrompt(oper_1, value_1, logic, oper_2, value_2);
    cin >> userInput;
    
    while (!valid)
    {
        valid = true; // assume userInput is valid
        
        if (cin.fail()) // no extraction took place
        {
            cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            cin.ignore(1000, '\n'); // clear out the bad input from the stream
            valid = false; // try again
        }
        
        else
        {
            cin.ignore(1000, '\n'); // clear out any additional input from the stream
            if (cin.gcount() > 1) // if we cleared out more than one additional character
            {
                valid = false;// we'll consider this input to be invalid
            }
            else // input is an int
            {
                // now validate user input against criteria if necessary
                valid = passedCriteria (userInput, oper_1, value_1, logic,
                                        oper_2, value_2);
            }
        }
        
        // let the user know the input was invalid and prompt them to reenter
        if (!valid)
        {
            cout << "Invalid input!" << endl;
            cout << prompt << "(an int";
            printPrompt(oper_1, value_1, logic, oper_2, value_2);
            cin >> userInput;
        }
    }
    return userInput;
}

// *****************************************************************************
// passCriteria
//
// This function takes a few parameters representing criterias to be checked
// in the getInt or getDouble function. It will then check the user input
// accordingly and return a boolean as the result.
// *****************************************************************************
bool passedCriteria (double userInput, int oper_1, double value_1,
                     int logic, int oper_2, double value_2)
{
    bool passed;
    
    // there is AT MOST one logic check.
    if (logic == NO_LOGIC)
    {
        // there is NO logic check
        if (oper_1 == NO_CHECK)
        {
            passed = true; // input is good by default
        }
        // there is one logic check
        else
        {
            passed = checkLogic(userInput, oper_1, value_1);
        }
    }
    // there are two logic checks linked by operator AND
    else if (logic == AND)
    {
        passed = checkLogic(userInput, oper_1, value_1) &&
        checkLogic(userInput, oper_2, value_2);
    }
    // there are two logic checks linked by operator OR
    else if (logic == OR)
    {
        passed = checkLogic(userInput, oper_1, value_1) ||
        checkLogic(userInput, oper_2, value_2);
    }
    return passed;
}

// *****************************************************************************
// checkLogic
//
// This function takes three ints as parameters representing the first value,
// the operator to compare, and the second value. It will use enum logic declared
// in Utilities.hpp to translate an int to an operator for easier representation.
// It will return a boolean according to the numerical comparison. It will also
// let the programmer know if the oper parameter was entered incorrectly
// (no possible translation in operators enum).
// *****************************************************************************
bool checkLogic(double value_1, int oper, double value_2)
{
    switch (oper)
    {
        case NO_CHECK:
            return true;
        case EQUAL:
            return value_1 == value_2;
        case DIFF:
            return value_1 != value_2;
        case GREATER:
            return value_1 > value_2;
        case SMALLER:
            return value_1 < value_2;
        case EQ_GREATER:
            return (value_1 == value_2) || (value_1 > value_2);
        case EQ_SMALLER:
            return (value_1 == value_2) || (value_1 < value_2);
        default:
            break;
    }
    // in case of accidentally entering wrong oper parameter
    cout << "Check oper parameter in checkLogic in Utilities!" << endl;
    return false;
}

// *****************************************************************************
// printPrompt
//
// This function takes a string prompt (required) and five optional ints
// representing the operators and values as parameters (usually passed by the
// getInt function). These five optional parameters are default to 0. It will
// then print the prompt dynamically to let the user know the range of the
// integer input that getInt will accept.
// *****************************************************************************
void printPrompt(int oper_1, double value_1,
                 int logic, int oper_2, double value_2)
{
    
    switch (logic)
    {
        case NO_LOGIC:
            checkLogicToPrintPrompt(oper_1, value_1);
            break;
        case AND:
            checkLogicToPrintPrompt(oper_1, value_1, false);
            cout << "and";
            checkLogicToPrintPrompt(oper_2, value_2);
            break;
        case OR:
            checkLogicToPrintPrompt(oper_1, value_1, false);
            cout << "or";
            checkLogicToPrintPrompt(oper_2, value_2);
            break;
        default:
            break;
    }
}

// *****************************************************************************
// checkLogicToPrintPrompt
//
// This function takes an int to represent an operator, an int value, and a
// boolean about whether it will print a closing parenthesis (default to be true)
// as parameters. It will then print to console appropriate logical operators,
// the value, and a closing parenthesis (as necessary).
// *****************************************************************************
void checkLogicToPrintPrompt(int oper, double value, bool printClosingParenthesis)
{
    switch (oper)
    {
        case NO_CHECK:
            // do nothing
            break;
        case EQUAL:
            cout << " =";
            break;
        case DIFF:
            cout << " !=";
            break;
        case GREATER:
            cout << " >";
            break;
        case SMALLER:
            cout << " <";
            break;
        case EQ_GREATER:
            cout << " >=";
            break;
        case EQ_SMALLER:
            cout << " <=";
            break;
        default:
            break;
    }
    
    if (oper != NO_CHECK)
    {
        cout << " " << value;
    }
    
    // in case there are two logic checks in getInt, we don't want a closing
    // parenthesis in the middle of the prompt.
    if (printClosingParenthesis)
    {
        cout << "): ";
    }
    else
    {
        cout << " ";
    }
}

// *****************************************************************************
// getRandomInt
// This function takes an int for min value and an int for max value and then
// generate and return a pseudo-random int in the range from min
// to max inclusive.
//
// CREDIT: I got the idea of this function through the following link
// http://www.cplusplus.com/forum/beginner/85134/
//
//******************************************************************************
int getRandomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// *****************************************************************************
// getString
//
// This function takes a string prompt as parameter. It will prompt the user
// for a string and return the string.
// *****************************************************************************
string getString(string prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

// *****************************************************************************
// getYesNo
//
// This function takes a string prompt as parameter. It will then call the getInt
// function to prompt the user to answer a yes/no question with 0 being NO and
// 1 being YES. It will return a boolean representing the choice (true is YES,
// false is NO).
// *****************************************************************************
bool getYesNo(string prompt)
{
    return getInt(prompt, EQUAL, 0, OR, EQUAL, 1) != 0;
}

// *****************************************************************************
// getChar(string prompt)
//
// This function prompts the user for a char, validates if the char is one of
// the chars specified in the if conditions below, and returns the char.
// *****************************************************************************
char getChar(string prompt)
{
    while (true)
    {
        string input = getString(prompt);
        
        if (input.length() == 1 && (input[0] == 'a' || input[0] == 'd' ||
                                    input[0] == 'w' || input[0] == 's' ||
                                    input[0] == 'x' || input[0] == 'p' ||
                                    input[0] == 'c' || input[0] == 'u' ||
                                    input[0] == 'i' || input[0] == 'g' ||
                                    input[0] == 'l' ))
        {
            return input[0];
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

// *****************************************************************************
// getCharYesNO(string prompt)
//
// This function prompts the user for a char, validates if the char is one of
// is either 'y' or 'n' for a yes/ no question, and returns the char.
// *****************************************************************************
char getCharYesNo(string prompt)
{
    while (true)
    {
        string input = getString(prompt);
        
        if (input.length() == 1 && (input[0] == 'y' || input[0] == 'n'))
        {
            return input[0];
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}



