#pragma once

#include <memory>
#include <stack>

#include "../command/command.hpp"

class Calculator {
public:
    void compute(std::unique_ptr<Command> command);
    void undo();
    void redo();

    int value() const { return current_value_; }

private:
    int current_value_ = 0;

    std::stack<std::unique_ptr<Command>> undo_stack_;
    std::stack<std::unique_ptr<Command>> redo_stack_;
};
