#pragma once

#include "state/state.h"

class ConcreteStateC : public State {
public:
    ConcreteStateC() : State("State C") {}

    void request3(Context* context) override;
};
