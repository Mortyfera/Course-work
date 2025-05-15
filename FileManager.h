#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager{
    public:
    static std::ofstream openFile(const std::string &file_name);
};

#endif