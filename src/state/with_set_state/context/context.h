#pragma once

#include <memory>

#include "state/state.h"

class Context {
    std::unique_ptr<State> state_;

public:
    Context();

    void set_state(std::unique_ptr<State> new_state);

    void request1();
    void request2();
    void request3();
};
