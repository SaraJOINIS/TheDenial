#pragma once
#include "StudentState.h"
#include <iostream>

class TargettedState : public StudentState {
public:
    void initAction() override;
    void complain();
    void cry();
};
