#pragma once

#include "state/state.h"

class ConcreteStateB : public State {
public:
    ConcreteStateB() : State("State B") {}

    std::unique_ptr<State> request2() override;
};
