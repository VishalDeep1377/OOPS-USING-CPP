#include "ScoreManager.h"
#include <iostream>

int ScoreManager::totalDamageDealt = 0;
int ScoreManager::totalUnitsKilled = 0;

void ScoreManager::addDamageDealt(int amount) { totalDamageDealt += amount; }
void ScoreManager::recordKill() { totalUnitsKilled++; }

void ScoreManager::displayFinalScore() {
    std::cout << "\n\033[33;1m================================\n"
              << "       FINAL MATCH STATS        \n"
              << "================================\033[0m\n"
              << "Total Damage Dealt: " << totalDamageDealt << "\n"
              << "Total Units Destroyed: " << totalUnitsKilled << "\n"
              << "================================\n\n";
}