#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <string>

// Pure Abstract Base Class (Interface)
class GameEntity {
public:
    virtual ~GameEntity() {}
    virtual std::string getName() const = 0;
    virtual bool isAlive() const = 0;
    virtual void takeDamage(int amount) = 0;
    virtual void displayStats() const = 0;
};

#endif