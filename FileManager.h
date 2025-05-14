#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager{
    public:
    static void writeToFile(const std::string &file_name, const std::string &content);
}

#endif