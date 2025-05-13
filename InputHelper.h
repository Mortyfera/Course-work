#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>

class InputHelper{
    public:
    static int getIntInput(const std::string &prompt, int min_val, int max_val);
    static char getCharInput(const std::string &prompt, char option1, char option2);
};

#endif