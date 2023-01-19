#pragma once

#include <memory>
#include <stack>

#include "../command/command.hpp"

class Calculator {
public:
    void compute(std::unique_ptr<Command> command);
    void undo();

    int value() const { return current_value_; }

private:
    int current_value_ = 0;
    std::stack<std::unique_ptr<Command>> command_stack_;
};
