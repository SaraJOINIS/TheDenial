#include "TargettedState.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

void TargettedState::initAction() {
    int randomNumber = rand() % 4;
    switch (randomNumber) {
        case 0:
            complain();
            break;
        case 1:
            cry();
            break;
        default:
            break;
    }
}

void TargettedState::complain() {
    std::cout << "Student is complaining!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}

void TargettedState::cry() {
    std::cout << "Student is crying!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}
