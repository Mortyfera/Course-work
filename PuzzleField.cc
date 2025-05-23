/* ----------------------------------------------------------------<Header>-
 Name: PuzzleField.cc
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Is responsible for solving a puzzle automatically and through user,
 filling in the field automatically and through user, and prints a field.
 ------------------------------------------------------------------</Header>-*/

#include "PuzzleField.h"
#include "InputHelper.h"
#include <iostream>

using namespace std;

PuzzleField::PuzzleField(){
    resetField();
}

/* ---------------------------------------------------------------------[<]-
 Method: resetField()
 Synopsis: Resets states af all cells.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::resetField(){
    int template_regions[ROWS][COLS] = {
        {1, 1, 1, 2, 3, 3, 3},
        {1, 1, 4, 2, 2, 3, 3},
        {1, 4, 4, 2, 2, 2, 3},
        {4, 4, 4, 5, 6, 6, 6},
        {7, 8, 8, 8, 6, 6, 9},
        {7, 7, 8, 8, 6, 9, 9},
        {7, 7, 7, 8, 9, 9, 9}
    };

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            field[i][j].number = -1;
            field[i][j].state = WHITE;
            field[i][j].region = template_regions[i][j];
        }
    }
}

/* ---------------------------------------------------------------------[<]-
 Method: fillFieldManual()
 Synopsis: Fills field with values user enters.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::fillFieldManual(){
    cout << "\nEnter cell values (-1 for blank), for each row:\n";
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            string prompt = "(" + to_string(i) + "," + to_string(j) + ") = ";
            field[i][j].number = InputHelper::getIntInput(prompt, -1, 9);
        }
    }
}

/* ---------------------------------------------------------------------[<]-
 Method: fillFieldAuto()
 Synopsis: Fills field with random values.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::fillFieldAuto(){
    srand(time(0));
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(rand() % 10 < 7){
                field[i][j].number = rand() % 9+1;
            } else{
                field[i][j].number = -1;
            }
        }
    }
}

/* ---------------------------------------------------------------------[<]-
 Method: setCellStateManual(ostream &stream)
 Synopsis: Allows user to set state of chosen cells.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::setCellStateManual(ostream &stream){
    cout << "\nEnter coordinates(row col, from 0 to 6) of a cell\nyou want to assign to black/white\nenter '-1' to stop\n(if you can't solve the puzzle enter '-2':\n";
	stream << "\nEnter coordinates(row col, from 0 to 6) of a cell\nyou want to assign to black/white\nenter '-1' to stop\n(if you can't solve the puzzle enter '-2':\n";
    while(true){
        int x = InputHelper::getIntInput("Row (-1 - to stop, -2 - can't find solution): ", -2, ROWS-1);
        if(x == -1){
            break;
        }
		else if(x == -2){
			cout << "\nPuzzle can't be solved.\n";
			stream << "\nPuzzle can't be solved.\n";
			return;
		}

        int y = InputHelper::getIntInput("Column: ", 0, COLS-1);
		
		int choice = InputHelper::getCharInput("\nIf you want to assign cell to white enter 'w'\nif you want to assign cell to black enter 'b': ", 'w', 'b');
		if(choice == 'b'){
			field[x][y].state = BLACK;
		}
		else{
			field[x][y].state = WHITE;
		}
		print(stream);
    }
	cout << "\nPuzzle solved:\n";
	stream << "\nPuzzle solved:\n";
	print(stream);
}

/* ---------------------------------------------------------------------[<]-
 Method: solve(ostream &stream)
 Synopsis: Performs the algorithm that solves the puzzle.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::solve(ostream &stream){
    int temporary_field[MAX_REGION_ID][6];//9 regions, every region has 6 elements, exept for a region 5

    for(int id=1; id<10; id++){
        int col = 0;
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(field[i][j].region == id){
                    int row = id-1;
                    temporary_field[row][col] = field[i][j].number;
                    col++;
                }
            }
        }
    }

    for(int i=0; i<MAX_REGION_ID; i++){
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
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(field[i][j].region == id){
                    int row = id-1;
                    if(temporary_field[row][col] == 0){
                        field[i][j].state = BLACK;
                        cout << "Cell (" << i << "," << j << ") is assigned to black.\n";
                        stream << "Cell (" << i << "," << j << ") is assigned to black.\n";
						print(stream);
                    }
                    col++;
                }
            }
        }
    }

    for (int id=1; id<=MAX_REGION_ID; id++) {
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (field[i][j].region == id && field[i][j].state == BLACK) {
                    int move_row[] = {-1, 1, 0, 0};
                    int move_col[] = {0, 0, -1, 1};
                    
                    for (int d = 0; d < 4; d++) {
                        int new_i = i + move_row[d];
                        int new_j = j + move_col[d];
                        
                        if (new_i >= 0 && new_i < ROWS && new_j >= 0 && new_j < COLS && field[new_i][new_j].region == id && field[new_i][new_j].state == BLACK){
                            field[new_i][new_j].state = WHITE;
                            cout << "Cell (" << new_i << "," << new_j << ") is assigned to white.\n";
                            stream << "Cell (" << new_i << "," << new_j << ") is assigned to white.\n";
							print(stream);
                            int target_number = field[new_i][new_j].number;
                            bool replaced = false;
                            
                            for (int x=0; x<ROWS && !replaced; x++) {
                                for (int y=0; y<COLS && !replaced; y++) {
                                    if (field[x][y].region == id && field[x][y].state != BLACK && field[x][y].number == target_number && !(x == new_i && y == new_j)) {
                                        field[x][y].state = BLACK;
                                        cout << "Cell (" << x << "," << y << ") is assigned to black.\n";
                                        stream << "Cell (" << x << "," << y << ") is assigned to black.\n";
										print(stream);
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

    for (int id=1; id<=MAX_REGION_ID; id++) {
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (field[i][j].region == id && field[i][j].state == BLACK) {
                    int move_row[] = {-1, 1, 0, 0};
                    int move_col[] = {0, 0, -1, 1};
                    
                    for (int d = 0; d < 4; d++) {
                        int new_i = i + move_row[d];
                        int new_j = j + move_col[d];
                        
                        if (new_i >= 0 && new_i < ROWS && new_j >= 0 && new_j < COLS && field[new_i][new_j].region == id && field[new_i][new_j].state == BLACK){
                            cout << "Puzzle can't be solved.\n";
                            stream << "Puzzle can't be solved.\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "Puzzle solved:\n";
    stream << "Puzzle solved:\n";
    print(stream);
}

/* ---------------------------------------------------------------------[<]-
 Method: print(ostream &stream)
 Synopsis: Prints a field.
 ---------------------------------------------------------------------[>]-*/
void PuzzleField::print(ostream &stream) const {
	cout << "Field:\n";
	stream << "Field:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (field[i][j].state == BLACK){
				cout << "X ";
				stream << "X ";
			}
            else if (field[i][j].number != -1){
				cout << field[i][j].number << " ";
				stream << field[i][j].number << " ";
			}
            else{
				cout << ". ";
				stream << ". ";
			}
        }
        cout << "\n";
		stream << "\n";
    }
	cout << "\n\n";
	stream << "\n\n";
}