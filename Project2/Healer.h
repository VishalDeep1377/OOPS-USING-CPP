#ifndef HEALER_H
#define HEALER_H
#include "Unit.h"
#include <iostream>

class Healer : public Unit {
public:
    Healer(std::string n) : Unit(n, 80, 10, 10) {}
    
    void useAbility(Unit* target) override {
        if(target) {
            std::cout << "\033[36m" << name << " uses DIVINE HEAL on " << target->getName() << "!\033[0m\n";
            target->heal(50);
        }
    }
};
#endif