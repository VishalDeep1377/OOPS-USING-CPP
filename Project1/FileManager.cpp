#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveToFile(const Planner& planner, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file to save data.\n";
        return;
    }
    for (const Task* t : planner.getTasks()) {
        file << t->getId() << "|" << t->getTitle() << "|" 
             << t->getDaysToDeadline() << "|" << t->isCompleted() 
             << "|" << t->getCategory() << "\n";
    }
    file.close();
    std::cout << "💾 System data successfully saved to " << filename << "\n";
}

void FileManager::loadFromFile(Planner& planner, const std::string& filename) {
    // Simplified implementation - validates if data integration starts
    // For an extension, we parse the raw strings dynamically back into objects.
    std::cout << "📂 Attempted data initialization from " << filename << "\n";
}