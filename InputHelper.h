#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>

class InputHelper{
    public:
    static int getIntInput(const std::string &prompt, int min_value, int max_value);
    static char getCharInput(const std::string &prompt, char option1, char option2);
};

#endif