#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"

class Enemy : public Player {
public:
    Enemy(std::string n);
    
    // Advanced AI Logic System
    void takeTurn(std::vector<Unit*>& playerTeam);
    Unit* getWeakestTarget(std::vector<Unit*>& opponents);
};
#endif