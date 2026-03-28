#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Planner.h"
#include <string>

class FileManager {
public:
    static void saveToFile(const Planner& planner, const std::string& filename);
    static void loadFromFile(Planner& planner, const std::string& filename);
};
#endif