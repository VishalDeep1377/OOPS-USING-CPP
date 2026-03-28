#ifndef WARRIOR_H
#define WARRIOR_H
#include "Unit.h"
#include <iostream>

class Warrior : public Unit {
public:
    Warrior(std::string n) : Unit(n, 100, 25, 15) {}
    
    void useAbility(Unit* target) override {
        if(target) {
            std::cout << "\033[36m" << name << " uses BLADE DANCE! (Attacks twice)\033[0m\n";
            this->attack(target);
            this->attack(target);
        }
    }
};
#endif