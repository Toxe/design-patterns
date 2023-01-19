#pragma once

#include "command.hpp"

class Multiply : public Command {
public:
    explicit Multiply(const int operand) : operand_{operand} { }

    int execute(int current_calculator_value) const override { return current_calculator_value * operand_; }
    int undo(int current_calculator_value) const override { return current_calculator_value / operand_; }

private:
    int operand_;
};
