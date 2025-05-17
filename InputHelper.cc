/* ----------------------------------------------------------------<Header>-
 Name: InputHelper.cc
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Cheks user's char and int input.
 ------------------------------------------------------------------</Header>-*/

#include "InputHelper.h"
#include <iostream>
#include <limits>

using namespace std;

/* ---------------------------------------------------------------------[<]-
 Method: getIntInput(const string &prompt, int min_value, int max_value)
 Synopsis: Cheks user's int input.
 ---------------------------------------------------------------------[>]-*/
int InputHelper::getIntInput(const string &prompt, int min_value, int max_value){
    int value;
    while(true){
        cout << prompt;
        cin >> value;

        if(cin.fail() || value < min_value || value > max_value){
            cout << "Invalid input. Try again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
        } else {
            return value;
        }
    }
}

/* ---------------------------------------------------------------------[<]-
 Method: getIntInput(const string &prompt, int min_value, int max_value)
 Synopsis: Cheks user's char input.
 ---------------------------------------------------------------------[>]-*/
char InputHelper::getCharInput(const string &prompt, char option1, char option2){
    char input;
    while(true){
        cout << prompt;
        cin >> input;
        input = tolower(input);
        if(input == option1 || input == option2){
            return input;
        } else {
            cout << "Invalid input. Try again.\n";
            cin.ignore(1000, '\n');
        }
    }
}