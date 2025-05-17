/* ----------------------------------------------------------------<Header>-
 Name: PuzzleField.h
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Is responsible for solving a puzzle automatically and through user,
 filling in the field automatically and through user, and prints a field.
 ------------------------------------------------------------------</Header>-*/

#ifndef PUZZLE_FIELD_H
#define PUZZLE_FIELD_H

#include <iostream>

const int ROWS = 7;
const int COLS = 7;
const int MAX_REGION_ID = 9;

enum CellState{
    WHITE,
    BLACK
};

struct Cell{
    int number;
    CellState state;
    int region;
};

class PuzzleField{
    private:
    Cell field[ROWS][COLS];

    public:
    PuzzleField();

/* ---------------------------------------------------------------------[<]-
 Method: resetField()
 Synopsis: Resets states af all cells.
 ---------------------------------------------------------------------[>]-*/
    void resetField();
/* ---------------------------------------------------------------------[<]-
 Method: fillFieldManual()
 Synopsis: Fills field with values user enters.
 ---------------------------------------------------------------------[>]-*/
    void fillFieldManual();
/* ---------------------------------------------------------------------[<]-
 Method: fillFieldAuto()
 Synopsis: Fills field with random values.
 ---------------------------------------------------------------------[>]-*/
    void fillFieldAuto();
/* ---------------------------------------------------------------------[<]-
 Method: setCellStateManual(ostream &stream)
 Synopsis: Allows user to set state of chosen cells.
 ---------------------------------------------------------------------[>]-*/
    void setCellStateManual(std::ostream &stream);
/* ---------------------------------------------------------------------[<]-
 Method: solve(ostream &stream)
 Synopsis: Performs the algorithm that solves the puzzle.
 ---------------------------------------------------------------------[>]-*/
    void solve(std::ostream &stream);
/* ---------------------------------------------------------------------[<]-
 Method: print(ostream &stream)
 Synopsis: Prints a field.
 ---------------------------------------------------------------------[>]-*/
    void print(std::ostream &stream) const;
};
#endif