#include "InputHelper.h"
#include <iostream>
#include <limits>

using namespace std;

int InputHelper::getIntInput(const string &prompt, int min_val, int max_val){
    int value;
    while(true){
        cout << prompt;
        cin >> value;

        if(cin.fail() || value < min_val || value > max_val){
            cout << "Invalid input. Enter a number between " << min_value << " and " << max_val << ".\n";
            cin.ignore();
            cin.ignore(1000, '\n');
        } else {
            return value;
        }
    }
}

char InputHelper::getCharInput(const string &prompt, char option1, char option2){
    char input;
    while(true){
        cout << prompt << " (" << option1 << "/" << option2 << "): ";
        cin >> input;
        input = tlower(input);
        if(input == option1 || input == option2){
            return input;
        } else {
            cout << "Invalid choice. Try again.\n";
            cin.ignore(1000, '\n');
        }
    }
}