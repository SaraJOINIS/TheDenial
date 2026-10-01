#pragma once

class StudentState {
public:
    virtual ~StudentState() = default;

    // Defines the action when the state is initialized
    virtual void initAction() = 0;
};
