#pragma once
#include <string>

class Character {
protected:
    std::string name; // Character name

public:
    Character(const std::string& name) : name(name) {}
    virtual ~Character() = default;

    // Getter for character name
    std::string getName() const { return name; }
};
