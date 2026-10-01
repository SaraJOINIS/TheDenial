#pragma once
#include "Character.h"
#include "Student.h"

class Protagonist : public Character {
public:
    Protagonist(const std::string& name) : Character(name) {}

    // Punishes a student (changes their state)
    void punish(Student& student);
};
