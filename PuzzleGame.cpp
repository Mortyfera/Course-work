#include "PuzzleGame.h"
#include "InputHelper.h"
#include "PuzzleField.h"
#include "FileManager.h"
#include <iostream>

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
    while(true){
        PuzzleField puzzle;

        stream << "New puzzle.\n";

        int fill_mode = InputHelper::getIntInput("Choose a way to fill in the field (1 - manually, 2 - automatically(randomly by a computer)): ", 1, 2);
        stream << "Choose a way to fill in the field (1 - manually, 2 - automatically(randomly by a computer)): " << solve_mode << ".\n";
        int solve_mode = InputHelper::getIntInput("Choose a way to solve a puzzle (1 - manually, 2 - automatically(by a program)): ", 1, 2);
        stream << "Choose a way to solve a puzzle (1 - manually, 2 - automatically(by a program)): " << solve_mode << ".\n";

        if(fill_mode == 1){
            puzzle.fillFieldManual();
        }
        else{
            puzzle.fillFieldAuto();
        }

        if(solve_mode == 1){
            puzzle.setBlackCellsManual();
            cout << "\nField:\n";
            stream << "\nField:\n";
            puzzle.print(stream);
        }

        if(solve_mode == 2 && puzzle.solve()){
            cout << "Solved:\n";
            puzzle.print(stream);
        }
        else if(solve_mode == 2){
            cout << "Can't solve a puzzle.\n";
            stream << "Can't solve a puzzle.\n";
        }

        char continuation = InputHelper::getCherInput("Do you want to solve another puzzle? (y/n): ", 'y', 'n');
        if(continuation == 'n'){
            break;
        }
    }
}