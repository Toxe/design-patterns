#include "calculator.hpp"

#include <utility>

void Calculator::compute(std::unique_ptr<Command> command)
{
    current_value_ = command->execute(current_value_);
    command_stack_.push(std::move(command));
}

void Calculator::undo()
{
    if (command_stack_.empty())
        return;

    auto command = std::move(command_stack_.top());
    command_stack_.pop();

    current_value_ = command->undo(current_value_);
}
