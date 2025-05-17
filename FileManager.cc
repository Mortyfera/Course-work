/* ----------------------------------------------------------------<Header>-
 Name: FileManager.cc
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Provides secure work with files.
 ------------------------------------------------------------------</Header>-*/

#include "FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

/* ---------------------------------------------------------------------[<]-
 Method: openFile(const string &file_name)
 Synopsis: Provides secure opening of a file and hanles errors with files.
 ---------------------------------------------------------------------[>]-*/
ofstream FileManager::openFile(const string &file_name){
    ofstream fout(file_name, ios::app);
    if(!fout){
        cerr << "Error opening a file " << file_name << " .\n";
    }
    return fout;
}