#include "Player.h"
#include <iostream>

Player::Player(std::string n) : name(n) {}

Player::~Player() {
    for (Unit* u : team) {
        delete u; // Clean up dynamic memory
    }
    team.clear();
}

void Player::addUnit(Unit* unit) {
    team.push_back(unit);
}

bool Player::hasAliveUnits() const {
    for (const Unit* u : team) {
        if (u->isAlive()) return true;
    }
    return false;
}

void Player::displayTeam() const {
    std::cout << "\n--- " << name << "'s Team ---\n";
    for (size_t i = 0; i < team.size(); ++i) {
        std::cout << i + 1 << ". ";
        team[i]->displayStats();
    }
}

std::vector<Unit*>& Player::getTeam() { return team; }
std::string Player::getName() const { return name; }