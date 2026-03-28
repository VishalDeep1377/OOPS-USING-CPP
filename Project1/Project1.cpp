// Project: LifeLens Lite – AI-like Smart Task Planner
#include <iostream>
#include <stdexcept>
#include "User.h"
#include "Planner.h"
#include "StudyTask.h"
#include "WorkTask.h"
#include "HealthTask.h"
#include "PersonalTask.h"
#include "Scheduler.h"
#include "Analytics.h"
#include "SuggestionEngine.h"
#include "FileManager.h"

using namespace std;

void displayMenu() {
    cout << "\n===============================\n"
         << " LIFE-LENS LITE (AI PLANNER) \n"
         << "===============================\n"
         << "1. Add Task\n"
         << "2. View Tasks\n"
         << "3. Complete Task\n"
         << "4. View Optimal Schedule\n"
         << "5. View Analytics\n"
         << "6. Get AI Suggestions\n"
         << "7. Save & Exit\n"
         << "Select an option: ";
}

int main() {
    User user("Alex", 25, 8, "High Performance");
    user.displayProfile();

    Planner planner;
    FileManager::loadFromFile(planner, "data_save.txt");

    // Pre-populating some tasks to demonstrate OOP Polymorphism immediately
    planner.addTask(new StudyTask("C++ OOP Basics", "Read about Polymorphism", 1));
    planner.addTask(new HealthTask("Gym", "Push Day", 0));
    planner.addTask(new WorkTask("Client Meeting", "Discuss Q3 Roadmap", 2));

    int choice = 0;
    while (choice != 7) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int type, days;
                string title, desc;
                cout << "Task Type (1:Study, 2:Work, 3:Health, 4:Personal): ";
                cin >> type;
                cout << "Title: "; cin.ignore(); getline(cin, title);
                cout << "Description: "; getline(cin, desc);
                cout << "Days to deadline: "; cin >> days;
                
                try { // Exception Handling Implementation
                    Task* newTask = nullptr;
                    if (type == 1) newTask = new StudyTask(title, desc, days);
                    else if (type == 2) newTask = new WorkTask(title, desc, days);
                    else if (type == 3) newTask = new HealthTask(title, desc, days);
                    else if (type == 4) newTask = new PersonalTask(title, desc, days);
                    else throw invalid_argument("Invalid task type entered!");
                    
                    planner.addTask(newTask);
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 2: planner.viewTasks(); break;
            case 3: {
                int id; cout << "Enter Task ID to complete: "; cin >> id;
                planner.completeTask(id); break;
            }
            case 4: Scheduler::suggestOptimalSchedule(planner); break;
            case 5: Analytics::generateReport(planner); break;
            case 6: SuggestionEngine::provideSuggestions(planner); break;
            case 7: 
                FileManager::saveToFile(planner, "data_save.txt");
                cout << "Exiting LifeLens Lite. Stay productive!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}
