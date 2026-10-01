#pragma once
#include "StudentState.h"
#include <iostream>

class BadBehaviourState : public StudentState {
public:
    void initAction() override;
    void playVideoGames();
    void watchFilms();
    void sleep();
};
