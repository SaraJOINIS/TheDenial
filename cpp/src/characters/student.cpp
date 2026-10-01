#include "Student.h"
#include "GoodBehaviourState.h"
#include "BadBehaviourState.h"
#include <iostream>

Student::Student(const std::string& name) : Character(name), state(nullptr) {}

StudentState* Student::getState() const {
    return state;
}

void Student::setState(StudentState* newState) {
    state = newState;
}

void Student::initState() {
    int randomNumber = rand() % 2;
    switch (randomNumber) {
        case 0:
            setState(new GoodBehaviourState());
            break;
        case 1:
            setState(new BadBehaviourState());
            break;
        default:
            break;
    }
    state->initAction();
    initState();
}
