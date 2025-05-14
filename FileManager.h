#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager{
    public:
    static std::ofstream openFile(const std::string &file_name);
    static void writeToFile(const std::string &file_name, const std::string &content);
}

#endif