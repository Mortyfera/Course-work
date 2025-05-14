#ifndef PUZZLE_FIELD_H
#define PUZZLE_FIELD_H

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
    int rows;
    int cols;

    public:
    PuzzleField();

    void resetField();
    void fillFieldManual();
    void fillFieldAuto();
    void setBlackCellsManual();
    bool solve(int x=0, int y=0);
    void print(std::ostream &stream = std::cout) const;
    bool areWhiteCellsConnected();
    bool inBounds(int x, int y) const;
    bool isNumberUnique();
    void outputStep(int x, int y, bool was_assigned_to_black, std::ostream &stream = std::cout);
};
#endif