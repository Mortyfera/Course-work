#include "InputHelper.h"
#include <iostream>
#include <limits>

using namespace std;

int InputHelper::getIntInput(const string &prompt, int min_value, int max_value){
    int value;
    while(true){
        cout << prompt;
        cin >> value;

        if(cin.fail() || value < min_value || value > max_value){
            cout << "Invalid input. Try again.\n";
			cin.ignore(1000, '\n');
        } else {
            return value;
        }
    }
}

char InputHelper::getCharInput(const string &prompt, char option1, char option2){
    char input;
    while(true){
        cout << prompt;
        cin >> input;
        input = tolower(input);
        if(input == option1 || input == option2){
            return input;
        } else {
            cout << "Invalid input. Try again.\n";
            cin.ignore(1000, '\n');
        }
    }
}