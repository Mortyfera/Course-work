#include "PuzzleField.h"
#include <iostream>

using namespace std;

PuzzleField::PuzzleField(){
    rows = cols = 7;
    resetField();
}

void PuzzleField::reserField(){
    int template_regions[7][7] = {
        {1, 1, 1, 2, 3, 3, 3},
        {1, 1, 4, 2, 2, 3, 3},
        {1, 4, 4, 2, 2, 2, 3},
        {4, 4, 4, 5, 6, 6, 6},
        {7, 8, 8, 8, 6, 6, 9},
        {7, 7, 8, 8, 6, 9, 9},
        {7, 7, 7, 8, 9, 9, 9}
    };

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            field[i][j].number = -1;
            field[i][j].state = WHITE;
            field[i][j].region = template_regions[i][j];
        }
    }
}
void fillFieldManual(){
    cout << "\nEnter cell values (-1 for blank), for each row:\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
        }
    }
    cout << "\nField:\n";
    print();
}
void fillFieldAuto(){
    srand(time(0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(){
                field[i][j].number = rand() % 9+1;
            } else{
                field[i][j].number = -1;
            }
        }
    }
    cout << "\nField";
    print();
}
void setBlackCellsManual(){}
void solve(int x=0, int y=0){}
void print() const{}
bool areWhiteCellsConnected(){}
bool inBounds(int x, int y) const{}
bool isNumberUnique(){}
void outputStep(int x, int y, bool was_assigned_to_black){}