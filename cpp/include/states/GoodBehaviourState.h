#pragma once
#include "StudentState.h"
#include <iostream>

class GoodBehaviourState : public StudentState {
public:
    void initAction() override;
    void work();
};
