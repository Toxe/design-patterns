#pragma once

#include <memory>
#include <string>

#include "state/state.h"

class Context {
    std::unique_ptr<State> state_;

    void update_state(std::unique_ptr<State> next_state);

public:
    Context();

    std::string request1();
    std::string request2();
    std::string request3();
};
