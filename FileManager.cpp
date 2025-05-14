#include "FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileManager::writeToFile(const string &file_name, const string &content){
    ofstream fout(file_name);
    if(!fout){
        cerr << "Error opening a file " << file_name << " for writing.\n";
        return;
    }
    fout << content;
    fout.close();
}

ofstream FileManager::openFile(const string &file_name){
    ofstream fout(file_name);
    if(!fout){
        cerr << "Error opening a file " << file_name << " .\n";
    }
    return fout;
}