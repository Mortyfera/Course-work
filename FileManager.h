/* ----------------------------------------------------------------<Header>-
 Name: FileManager.h
 Title: puzzle modified "Hitory" solver
 Group: TV-43
 Student: Olkhovska Y.I.
 Written: 2025-05-17
 Description: Write a program that solves modified puzzle "Hitory"
 and writes it and gives user a chance to write and solve a puzzle themselves.
 Synopsis: Provides secure work with files.
 ------------------------------------------------------------------</Header>-*/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager{
    public:
/* ---------------------------------------------------------------------[<]-
 Method: openFile(const string &file_name)
 Synopsis: Provides secure opening of a file and hanles errors with files.
 ---------------------------------------------------------------------[>]-*/
    static std::ofstream openFile(const std::string &file_name);
};

#endif