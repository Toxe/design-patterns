#pragma once

#include "state/state.h"

class ConcreteStateA : public State {
public:
    ConcreteStateA() : State("State A") {}

    void request1(Context* context) override;
};
