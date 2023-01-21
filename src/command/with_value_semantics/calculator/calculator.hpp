#pragma once

#include <stack>

#include "../command/command.hpp"

class Calculator {
public:
    void compute(Command command);
    void undo();
    void redo();

    int value() const { return current_value_; }

private:
    int current_value_ = 0;

    std::stack<Command> undo_stack_;
    std::stack<Command> redo_stack_;
};
