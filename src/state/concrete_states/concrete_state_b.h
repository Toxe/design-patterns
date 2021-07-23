#pragma once

#include "state/state.h"

class ConcreteStateB : public State {
public:
    ConcreteStateB() : State("State B") {}

    void request2(Context* context) override;
};
