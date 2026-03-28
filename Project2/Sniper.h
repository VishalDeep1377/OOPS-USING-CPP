#ifndef SNIPER_H
#define SNIPER_H
#include "Unit.h"
#include <iostream>

class Sniper : public Unit {
public:
    Sniper(std::string n) : Unit(n, 70, 40, 5) {}
    
    void useAbility(Unit* target) override {
        if(target) {
            std::cout << "\033[36m" << name << " uses HEADSHOT on " << target->getName() << "!\033[0m\n";
            // Ignores defense entirely
            target->takeDamage(attackDamage * 2 + target->getHp() * 0.1); // True damage + 10% max HP
        }
    }
};
#endif