#include "Enemy.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy(std::string n) : Player(n) {}

Unit* Enemy::getWeakestTarget(std::vector<Unit*>& opponents) {
    Unit* weakest = nullptr;
    for (Unit* u : opponents) {
        if (u->isAlive()) {
            if (!weakest || u->getHp() < weakest->getHp()) {
                weakest = u;
            }
        }
    }
    return weakest;
}

void Enemy::takeTurn(std::vector<Unit*>& playerTeam) {
    std::cout << "\n\033[35m=== " << name << "'s Turn (AI) ===\033[0m\n";
    
    for (Unit* u : team) {
        if (!u->isAlive()) continue;
        
        u->setDefending(false); // Reset defense state
        
        Unit* target = getWeakestTarget(playerTeam);
        if (!target) return; // All players dead

        int action = rand() % 3; // 0 = attack, 1 = ability, 2 = defend
        
        if (action == 0) {
            u->attack(target);
        } else if (action == 1) {
            u->useAbility(target); // AI blindly uses ability on weakest player target for now
        } else {
            std::cout << u->getName() << " takes a defensive stance!\n";
            u->setDefending(true);
        }
    }
}