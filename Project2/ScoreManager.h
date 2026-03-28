#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

// Static Manager Class for game states
class ScoreManager {
private:
    static int totalDamageDealt;
    static int totalUnitsKilled;
public:
    static void addDamageDealt(int amount);
    static void recordKill();
    static void displayFinalScore();
};

#endif