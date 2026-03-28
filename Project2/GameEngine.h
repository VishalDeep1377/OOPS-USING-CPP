#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Player.h"
#include "Enemy.h"

class GameEngine {
private:
    Player* human;
    Enemy* ai;
    int turnNumber;

public:
    GameEngine();
    ~GameEngine();
    void start();
};
#endif