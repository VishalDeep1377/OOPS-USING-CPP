#include "Task.h"

int Task::totalTasks = 0;

Task::Task(std::string t, std::string d, int dtd, std::string cat) 
    : title(t), description(d), daysToDeadline(dtd), completed(false), category(cat) {
    id = ++totalTasks;
}

Task::~Task() {}

int Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
bool Task::isCompleted() const { return completed; }
void Task::markCompleted() { completed = true; }
std::string Task::getCategory() const { return category; }
int Task::getDaysToDeadline() const { return daysToDeadline; }
int Task::getTotalTasks() { return totalTasks; }

// Operator Overloading for priority sorting
bool Task::operator<(const Task& other) const {
    // Higher priority first
    return this->calculatePriority() > other.calculatePriority(); 
}

void Task::display() const {
    std::cout << "[" << (completed ? "X" : " ") << "] ID: " << id 
              << " | " << title << " (" << category << ") | Priority: " 
              << calculatePriority() << " | Deadline: " << daysToDeadline << " days\n";
}