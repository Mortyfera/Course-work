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
    if(x==rows){
        return isNumberUnique();
    }

    int next_x = x, next_y = y+1;
    if(next_y == cols){
        next_y = 0;
        next_x++;
    }

    if(field[x][y].number == -1){
        return solve(next_x, next_y);
    }

    bool can_be_assigned_to_black = true;
    int move_row[4] = {-1, 1, 0, 0};
    int move_col[4] = {0, 0, -1, 1};

    for(int i=0; i<4; i++){
        int new_row = x + move_row[i];
        int new_col = y + move_col[i];
        if(inBounds(new_row, new_col) && field[new_row][new_col].state == BLACK){
            can_be_assigned_to_black = false;
        }
    }

    if(can_be_assigned_to_black){
        field[x][y].state = BLACK;
        outputStep(x, y, true);
        if(areWhiteCellsConnected() && solve(net_x, next_y)){
            return true;
        }
        field[x][y].state = WHITE;
    }

    if(solve(next_x, next_y)){
        return true;
    }
    return false;
}
void PuzzleField::print() const{
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(field[i][j].state = BLACK){
                cout << "X ";
            }
            else if(field.[i][j].number != -1){
                cout << field[i][j].number << " ";
            }
            else{
                cout << ". ";
            }
        }
        cout << "\n";
    }
}
bool PuzzleField::areWhiteCellsConnected(){
    int move_roe[4] = {-1, 1, 0, 0};
    int move_col[4] = {0, 0, -1, 1};

    for(int x=0; x<rows; x++){
        for(int y=0; y<cols; y++){
            if(field[x][y].state = BLACK){
                continue;
            }

            boll all_neighbors_black = true;

            for(int d=0; d<4; d++){
                int next_x = x + move_row[d];
                it next_y = y + move_col[d];

                if(inBounds(next_x, next_y) && field[next_x][next_y].state != BLACK){
                    all_neighbors_black = false;
                    break;
                }
            }

            if(all_neighbors_black){
                return false;
            }
        }
    }
    return true;
}
bool PuzzleField::inBounds(int x, int y) const{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}
bool PuzzleField::isNumberUnique(){
    int numbers[6];
    int index = -1;
    for(int region_id = 1; region_id <= MAX_REDION_ID; region_id++){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(field[i][j].state != BLACK && field[i][j].region == region_id){
                    int num = field[i][j].number;
                    index += 1;
                    if(num!= -1){
                        numbers[index] = num;
                    }
                }
            }
        }
        for(index = 0; index < 6; index++){
            for(int i = index+1; i<6; i++){
                if(numbers[index] == numbers[i]){
                    return false;
                }
            }
        }
        index = -1;
    }
    return true;
}
void PuzzleField::outputStep(int x, int y, bool was_assigned_to_black){
    if(was_assigned_to_black){
        cout << "Cell (" << x << ", " << y << ") was assigned to black.\n";
    }
    else{
        cout << "Cell (" << x << ", " << y << ") was assigned to white.\n";
    }
    print();
}