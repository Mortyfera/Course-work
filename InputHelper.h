/* ----------------------------------------------------------------<Header>-
 Name: InputHelper.h
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Cheks user's char and int input.
 ------------------------------------------------------------------</Header>-*/

#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>

class InputHelper{
    public:
/* ---------------------------------------------------------------------[<]-
 Method: getIntInput(const string &prompt, int min_value, int max_value)
 Synopsis: Cheks user's int input.
 ---------------------------------------------------------------------[>]-*/
    static int getIntInput(const std::string &prompt, int min_value, int max_value);
/* ---------------------------------------------------------------------[<]-
 Method: getIntInput(const string &prompt, int min_value, int max_value)
 Synopsis: Cheks user's char input.
 ---------------------------------------------------------------------[>]-*/
    static char getCharInput(const std::string &prompt, char option1, char option2);
};

#endif