#pragma once

#include "state/state.h"

class ConcreteStateA : public State {
public:
    ConcreteStateA() : State("State A") {}

    std::unique_ptr<State> request1() override;
};
