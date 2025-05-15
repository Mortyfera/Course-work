#include "FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream FileManager::openFile(const string &file_name){
    ofstream fout(file_name, ios::app);
    if(!fout){
        cerr << "Error opening a file " << file_name << " .\n";
    }
    return fout;
}