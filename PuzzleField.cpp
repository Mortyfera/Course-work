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
void PuzzleField::fillFieldManual(){
    cout << "\nEnter cell values (-1 for blank), for each row:\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            string prompt = "(" + to_string(i) + "," + to_string(j) + ") = ";
            field[i][j].number = InputHelper::getIntInput(prompt, -1, 9);
        }
    }
    cout << "\nField:\n";
    print();
}
void PuzzleField::fillFieldAuto(){
    srand(time(0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(rand() % 10 < 7){
                field[i][j].number = rand() % 9+1;
            } else{
                field[i][j].number = -1;
            }
        }
    }
    cout << "\nField";
    print();
}
void PuzzleField::setBlackCellsManual(){
    cout << "\nEmter coordinates(row col) of a cell you want to assign to black, -1 to stop:\n";
    while(true){
        int x = InputHelper::getIntInput("Row (-1 to stop): ", -1, rows-1);
        if(x == -1){
            break;
        }

        int y = InputHelper::getIntInput("Column: ", 0, cola-1);

        field[x][y].state = BLACK;
    }
}
void PuzzleField::solve(int x, int y){
    int temporary_field[9][6];

    for(int id=1; id<10; id++){
        int col = 0;
        for(int i=0; i<7; i++){
            for(int j=0; j<7; j++){
                if(field[i][j].region == id){
                    int row = id-1;
                    temporary_field[row][col] = field[i][j].number;
                    col++;
                }
            }
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<6; j++){
            for(int z=j+1; z<6; z++){
                if(temporary_field[i][j] != -1){
                    if(temporary_field[i][j] == temporary_field[i][z]){
                        temporary_field[i][j] = 0;
                    }
                }
            }
        }
    }

    for(int id=1; id<10; id++){
        int col = 0;
        for(int i=0; i<7; i++){
            for(int j=0; j<7; j++){
                if(field[i][j].region == id){
                    int row = id-1;
                    if(temporary_field[row][col] == 0){
                        field[i][j].state == BLACK;
                        cout << "Cell (" << i << "," << j << ") is assigned to black.\n";
                        stream << "Cell (" << i << "," << j << ") is assigned to black.\n";
                    }
                    col++;
                }
            }
        }
    }

    for (int id=1; id<=9; id++) {
        for (int i=0; i<7; i++) {
            for (int j=0; j<7; j++) {
                if (field[i][j].region == id && field[i][j].state == BLACK) {
                    int move_row[] = {-1, 1, 0, 0};
                    int move_col[] = {0, 0, -1, 1};
                    
                    for (int d = 0; d < 4; d++) {
                        int new_i = i + move_row[d];
                        int new_j = j + move_col[d];
                        
                        if (new_i >= 0 && new_i < 7 && new_j >= 0 && new_j < 7 && field[new_i][new_j].region == id && field[new_i][new_j].state == BLACK){
                            field[new_i][new_j].state = WHITE;
                            cout << "Cell (" << new_i << "," << new_j << ") is assigned to white.\n";
                            stream << "Cell (" << new_i << "," << new_j << ") is assigned to white.\n";
                            int target_number = field[new_i][new_j].number;
                            bool replaced = false;
                            
                            for (int x=0; x<7 && !replaced; x++) {
                                for (int y=0; y<7 && !replaced; y++) {
                                    if (field[x][y].region == id && field[x][y].state != BLACK && field[x][y].number == targetNumber && !(x == new_i && y == new_j)) {
                                        field[x][y].state = BLACK;
                                        cout << "Cell (" << x << "," << y << ") is assigned to black.\n";
                                        stream << "Cell (" << x << "," << y << ") is assigned to black.\n";
                                        replaced = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}