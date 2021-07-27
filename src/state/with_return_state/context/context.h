#pragma once

#include <memory>

#include "state/state.h"

class Context {
    std::unique_ptr<State> state_;

    void update_state(std::unique_ptr<State> next_state);

public:
    Context();

    void request1();
    void request2();
    void request3();
};
