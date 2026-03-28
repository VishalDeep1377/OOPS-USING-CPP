#include "User.h"
#include <iostream>

User::User(std::string n, int a, int wh, std::string pg) 
    : name(n), age(a), workHours(wh), productivityGoal(pg) {}

void User::displayProfile() const {
    std::cout << "\n=== User Profile ===\n"
              << "Name: " << name << " | Age: " << age << "\n"
              << "Goal: " << productivityGoal << " | Work Hrs: " << workHours << "\n"
              << "====================\n";
}