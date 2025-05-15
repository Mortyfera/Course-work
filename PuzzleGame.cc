#include "PuzzleGame.h"
#include "InputHelper.h"
#include "PuzzleField.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

void PuzzleGame::run(){
    string file_name;
    cout << "Enter name of a file you want to write result of a program to (example.txt): ";
    cin >> file_name;
    ofstream stream = FileManager::openFile(file_name);
    
    if(!stream){
        cerr << "Error: problem with a file.\n";
        return;
    }

    stream << "Start of a new program.\n";
	cout << "Rules:\nThe field is divided into 9 regions.\nYou need to color some cells black so that the numbers within each region do not repeat,\nand black cells within a region do not touch each other.\n'X' on the field means black cell, '.' on the field means empty cell.\n";
	stream << "Rules:\nThe field is divided into 9 regions.\nYou need to color some cells black so that the numbers within each region do not repeat,\nand black cells within a region do not touch each other.\n'X' on the field means black cell, '.' on the field means empty cell.\n";
	cout << "Division of regions on the field:\n";
	stream << "Division of regions on the field:\n";
	int template_regions[7][7] = {
        {1, 1, 1, 2, 3, 3, 3},
        {1, 1, 4, 2, 2, 3, 3},
        {1, 4, 4, 2, 2, 2, 3},
        {4, 4, 4, 5, 6, 6, 6},
        {7, 8, 8, 8, 6, 6, 9},
        {7, 7, 8, 8, 6, 9, 9},
        {7, 7, 7, 8, 9, 9, 9}
    };
	for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
			cout << template_regions[i][j] << " ";
			stream << template_regions[i][j] << " ";
        }
        cout << endl;
		stream << endl;
    }
    while(true){
        PuzzleField puzzle;

        stream << "New puzzle.\n";

        int fill_mode = InputHelper::getIntInput("Choose a way to fill in the field (1 - manually, 2 - automatically(randomly by a computer)): ", 1, 2);
        stream << "Choose a way to fill in the field (1 - manually, 2 - automatically(randomly by a computer)): " << fill_mode << ".\n";
        int solve_mode = InputHelper::getIntInput("Choose a way to solve a puzzle (1 - manually, 2 - automatically(by a program)): ", 1, 2);
        stream << "Choose a way to solve a puzzle (1 - manually, 2 - automatically(by a program)): " << solve_mode << ".\n";

        if(fill_mode == 1){
            puzzle.fillFieldManual();
			puzzle.print(stream);
        }
        else{
            puzzle.fillFieldAuto();
			puzzle.print(stream);
        }

        if(solve_mode == 1){
            puzzle.setBlackCellsManual(stream);
        }
        else{
            puzzle.solve(stream);
        }

        char continuation = InputHelper::getCharInput("Do you want to solve another puzzle? (y/n): ", 'y', 'n');
        if(continuation == 'n'){
            break;
        }
    }
	stream << "End of a program.\n\n\n";
}