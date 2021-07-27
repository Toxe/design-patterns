#pragma once

#include "state/state.h"

class ConcreteStateC : public State {
public:
    ConcreteStateC() : State("State C") {}

    std::unique_ptr<State> request3() override;
};
