#include "Unit.h"
#include "ScoreManager.h"
#include <iostream>
#include <algorithm>

int Unit::totalUnits = 0;

Unit::Unit(std::string n, int health, int attack, int def)
    : name(n), hp(health), maxHp(health), attackDamage(attack), defense(def), defending(false) {
    id = ++totalUnits;
}

Unit::~Unit() {}

std::string Unit::getName() const { return name; }
bool Unit::isAlive() const { return hp > 0; }
int Unit::getAttackDamage() const { return attackDamage; }
int Unit::getHp() const { return hp; }
bool Unit::isDefending() const { return defending; }
void Unit::setDefending(bool state) { defending = state; }

void Unit::takeDamage(int amount) {
    int actualDamage = std::max(1, amount - (defending ? (defense * 2) : defense));
    hp -= actualDamage;
    ScoreManager::addDamageDealt(actualDamage);
    if (hp < 0) hp = 0;
    std::cout << "\033[31m" << name << " takes " << actualDamage << " damage! (HP: " << hp << "/" << maxHp << ")\033[0m\n";
    if (!isAlive()) {
        std::cout << "\033[31;1m" << name << " has been defeated!\033[0m\n";
        ScoreManager::recordKill();
    }
}

void Unit::heal(int amount) {
    hp = std::min(maxHp, hp + amount);
    std::cout << "\033[32m" << name << " is healed for " << amount << "! (HP: " << hp << "/" << maxHp << ")\033[0m\n";
}

void Unit::attack(Unit* target) {
    std::cout << "\033[33m" << name << " attacks " << target->getName() << "!\033[0m\n";
    target->takeDamage(attackDamage);
}

void Unit::displayStats() const {
    std::cout << "[" << name << "] HP: " << hp << "/" << maxHp << " | ATK: " << attackDamage << " | DEF: " << defense << "\n";
}