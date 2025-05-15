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

    void resetField();
    void fillFieldManual();
    void fillFieldAuto();
    void setBlackCellsManual(std::ostream &stream);
    void solve(std::ostream &stream);
    void print(std::ostream &stream) const;
};
#endif