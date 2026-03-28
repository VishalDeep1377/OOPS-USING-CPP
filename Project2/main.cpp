/*
 * Project: CLI Strategy Game Engine
 * Demonstrates: Advanced OOP, Dynamic Memory, Polymorphism, Game Loop Architecture
 */
#include "GameEngine.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed randomness for AI and critical hits
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int choice = 0;
    while (choice != 3) {
        std::cout << "\n==================================\n"
                  << "  CLI STRATEGY ENGINE (C++ OOP)   \n"
                  << "==================================\n"
                  << "1. Start Local Game vs AI\n"
                  << "2. View Engine Architecture Info\n"
                  << "3. Exit Game\n"
                  << "Select: ";
        std::cin >> choice;

        if (choice == 1) {
            GameEngine engine;
            engine.start();
        } else if (choice == 2) {
            std::cout << "\n[ENGINE INFO]\nPowered by polymorphic behavior. The GameEngine manages abstract GameEntity classes. Extensible via virtual void overrides.\n";
        }
    }
    return 0;
}