#ifndef SUGGESTIONENGINE_H
#define SUGGESTIONENGINE_H
#include "Planner.h"

class SuggestionEngine {
public:
    static void provideSuggestions(const Planner& planner);
};
#endif