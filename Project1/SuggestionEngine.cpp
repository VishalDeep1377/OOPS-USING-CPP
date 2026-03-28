#include "SuggestionEngine.h"
#include <iostream>

void SuggestionEngine::provideSuggestions(const Planner& planner) {
    std::cout << "\n--- AI Insights & Suggestions ---\n";
    int healthIgnored = 0;
    int criticalPending = 0;

    for (const Task* t : planner.getTasks()) {
        if (!t->isCompleted()) {
            if (t->getCategory() == "Health") healthIgnored++;
            if (t->calculatePriority() >= 80) criticalPending++;
        }
    }

    if (healthIgnored > 1) {
        std::cout << "💡 Insight: You are frequently ignoring health tasks. Take a break!\n";
    }
    if (criticalPending > 0) {
        std::cout << "💡 Insight: Focus heavily on high-priority pending tasks right now.\n";
    }
    if (healthIgnored <= 1 && criticalPending == 0) {
        std::cout << "💡 Insight: Your schedule looks very balanced today. Keep it up.\n";
    }
}