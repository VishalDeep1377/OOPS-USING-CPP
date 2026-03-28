#ifndef TANK_H
#define TANK_H
#include "Unit.h"
#include <iostream>

class Tank : public Unit {
public:
    Tank(std::string n) : Unit(n, 150, 15, 20) {}
    
    void useAbility(Unit* target = nullptr) override {
        std::cout << "\033[36m" << name << " uses SHIELD WALL! Defense massively increased for this turn.\033[0m\n";
        setDefending(true);
        defense += 20; // Temporary boost
    }
    
    void resetAbility() {
        defense = 20; // Reset base defense
    }
};
#endif