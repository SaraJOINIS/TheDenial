#pragma once
#include "Character.h"
#include "StudentState.h"

class Student : public Character {
private:
    StudentState* state; // Current student state

public:
    Student(const std::string& name);

    // Get current state
    StudentState* getState() const;

    // Set new state
    void setState(StudentState* newState);

    // Initialize state
    void initState();
};
