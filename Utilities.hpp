// *****************************************************************************
// Program name: CS 162 Final Project
// Author: Khoa Nguyen
// Date: 03-14-17
// Description: This is the header file where all of the utility functions I
// have created are declared. These functions have high potential for
// reuseability in future programs. Also, all enums are defined here.
// *****************************************************************************

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <stdlib.h> // for srand, rand
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// all enums are defined here
enum direction {NORTH, EAST, SOUTH, WEST};
enum move {FORWARD, RIGHT, BACKWARD, LEFT};
enum operators {NO_CHECK, EQUAL, DIFF, GREATER, SMALLER, EQ_GREATER, EQ_SMALLER};
enum logic {NO_LOGIC, AND, OR};

int menu();

void help();

void printIntro();

int getInt(string prompt, int oper_1 = 0, int value_1 = 0,
           int logic = 0, int oper_2 = 0, int value_2 = 0);

bool passedCriteria (double userInput, int oper_1 = 0, double value_1 = 0,
                     int logic = 0, int oper_2 = 0, double value_2 = 0);

void printPrompt(int oper_1 = 0, double value_1 = 0,
                 int logic = 0, int oper_2 = 0, double value_2 = 0);

bool checkLogic(double x, int oper, double y);

void checkLogicToPrintPrompt(int operand, double value,
                             bool printClosingParenthesis = true);

int getRandomInt(int min, int max);

string getString(string prompt);

bool getYesNo(string prompt);

char getChar(string prompt);

char getCharYesNo(string prompt);

#endif
