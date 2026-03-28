#include "GameEngine.h"
#include "Tank.h"
#include "Sniper.h"
#include "Healer.h"
#include "Warrior.h"
#include "ScoreManager.h"
#include <iostream>

GameEngine::GameEngine() : turnNumber(1) {
    human = new Player("Commander (Player)");
    ai = new Enemy("Nexus AI");

    // Pre-load units for Demo
    human->addUnit(new Warrior("Arthur"));
    human->addUnit(new Sniper("Widow"));
    human->addUnit(new Healer("Mercy"));

    ai->addUnit(new Tank("Juggernaut"));
    ai->addUnit(new Warrior("Berserker"));
    ai->addUnit(new Sniper("Ghost"));
}

GameEngine::~GameEngine() {
    delete human;
    delete ai;
}

void GameEngine::start() {
    std::cout << "\033[36;1mWelcome to CLI WARS: Game Engine v1.0\033[0m\n";

    while (human->hasAliveUnits() && ai->hasAliveUnits()) {
        std::cout << "\n\033[33m--- TURN " << turnNumber << " ---\033[0m\n";
        
        // Human Turn
        human->displayTeam();
        ai->displayTeam();

        for (Unit* u : human->getTeam()) {
            if (!u->isAlive()) continue;
            if (!ai->hasAliveUnits()) break; // AI wiped out

            u->setDefending(false);

            std::cout << "\nCommanding " << u->getName() << " | 1. Attack  2. Ability  3. Defend: ";
            int action;
            std::cin >> action;

            if (action == 1 || action == 2) {
                std::cout << "Select Target (1-" << ai->getTeam().size() << "): ";
                int targetIdx;
                std::cin >> targetIdx;
                Unit* target = ai->getTeam()[targetIdx - 1];

                // If ability is heal, override target to ally
                if (action == 2 && dynamic_cast<Healer*>(u)) {
                    std::cout << "Select Ally to Heal (1-" << human->getTeam().size() << "): ";
                    std::cin >> targetIdx;
                    target = human->getTeam()[targetIdx - 1];
                }

                // If action is attack on dead target, fallback
                if (!target->isAlive() && action != 2) {
                    std::cout << "Target is already dead! Turn wasted.\n";
                    continue;
                }

                if (action == 1) u->attack(target);
                else u->useAbility(target);
            } 
            else if (action == 3) {
                u->setDefending(true);
                std::cout << u->getName() << " takes a defensive stance!\n";
            }
        }

        // AI Turn
        if (ai->hasAliveUnits()) {
            ai->takeTurn(human->getTeam());
        }

        turnNumber++;
    }

    // End Game State
    if (human->hasAliveUnits()) {
        std::cout << "\n\033[32;1mVICTORY! The AI has been defeated.\033[0m\n";
    } else {
        std::cout << "\n\033[31;1mDEFEAT! Your squad was wiped out.\033[0m\n";
    }

    ScoreManager::displayFinalScore();
}