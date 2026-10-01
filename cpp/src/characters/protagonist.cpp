#include "Protagonist.h"
#include "TargettedState.h"
#include <iostream>

void Protagonist::punish(Student& student) {
    std::cout << name << " is punishing " << student.getName() << "!" << std::endl;
    // student.setState(new TargettedState());
    // Change student state and await before initState again
}
