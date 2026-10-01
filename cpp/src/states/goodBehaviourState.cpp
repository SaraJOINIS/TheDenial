#include "GoodBehaviourState.h"
#include <chrono>
#include <thread>

void GoodBehaviourState::initAction() {
    work();
}

void GoodBehaviourState::work() {
    std::cout << "Student is working hard!" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
}
