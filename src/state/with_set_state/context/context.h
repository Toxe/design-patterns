#pragma once

#include <memory>
#include <string>

#include "state/state.h"

class Context {
    std::unique_ptr<State> state_;

public:
    Context();

    void set_state(std::unique_ptr<State> new_state);

    std::string request1();
    std::string request2();
    std::string request3();
};
