#include "BadBehaviourState.h"
#include <chrono>
#include <thread>

void BadBehaviourState::initAction() {
    int randomNumber = rand() % 4;
    switch (randomNumber) {
        case 0:
            playVideoGames();
            break;
        case 1:
            watchFilms();
            break;
        case 2:
            sleep();
            break;
        default:
            break;
    }
}

void BadBehaviourState::playVideoGames() {
    std::cout << "Student is playing video games!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}

void BadBehaviourState::watchFilms() {
    std::cout << "Student is watching films!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}

void BadBehaviourState::sleep() {
    std::cout << "Student is sleeping!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}
