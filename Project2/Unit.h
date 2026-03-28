#ifndef UNIT_H
#define UNIT_H
#include "GameEntity.h"
#include <string>
#include <iostream>

class Unit : public GameEntity {
protected:
    static int totalUnits; // Static tracking
    int id;
    std::string name;
    int hp;
    int maxHp;
    int attackDamage;
    int defense;
    bool defending;

public:
    Unit(std::string n, int health, int attack, int def);
    virtual ~Unit();

    std::string getName() const override;
    bool isAlive() const override;
    void takeDamage(int amount) override;
    void displayStats() const override;

    int getAttackDamage() const;
    int getHp() const;
    bool isDefending() const;
    
    void heal(int amount);
    void setDefending(bool state);

    // Core Polymorphic Combat Functions
    virtual void attack(Unit* target);
    virtual void useAbility(Unit* target) = 0; // Pure virtual
};
#endif