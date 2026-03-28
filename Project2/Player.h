#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include <vector>
#include <string>

class Player {
protected:
    std::string name;
    std::vector<Unit*> team;

public:
    Player(std::string n);
    virtual ~Player(); // Virtual destructor for dynamic memory

    void addUnit(Unit* unit);
    bool hasAliveUnits() const;
    void displayTeam() const;
    std::vector<Unit*>& getTeam();
    std::string getName() const;
};
#endif