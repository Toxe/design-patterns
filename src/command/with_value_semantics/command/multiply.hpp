#pragma once

#include <utility>

#include "command.hpp"

Command Multiply(const int operand)
{
    return Command{
        [=](const int current_calculator_value) { return current_calculator_value * operand; },
        [=](const int current_calculator_value) { return current_calculator_value / operand; }};
}
