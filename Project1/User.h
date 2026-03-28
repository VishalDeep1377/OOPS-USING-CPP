#ifndef USER_H
#define USER_H
#include <string>

class User {
private:
    std::string name;
    int age;
    int workHours;
    std::string productivityGoal;
public:
    User(std::string n = "Guest", int a = 20, int wh = 8, std::string pg = "Balanced");
    void displayProfile() const;
};
#endif