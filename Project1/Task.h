#ifndef TASK_H
#define TASK_H
#include <string>
#include <iostream>

class Task {
protected:
    static int totalTasks; // Static Member Tracking
    int id;
    std::string title;
    std::string description;
    int daysToDeadline;
    bool completed;
    std::string category;

public:
    Task(std::string t, std::string d, int dtd, std::string cat);
    virtual ~Task(); // Virtual destructor for dynamic memory cleanup

    // Abstraction & Polymorphism: Pure virtual function
    virtual int calculatePriority() const = 0;

    int getId() const;
    std::string getTitle() const;
    bool isCompleted() const;
    void markCompleted();
    std::string getCategory() const;
    int getDaysToDeadline() const;
    static int getTotalTasks();

    bool operator<(const Task& other) const; // Operator Overloading
    virtual void display() const;
};
#endif