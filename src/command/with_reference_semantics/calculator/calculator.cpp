#include "calculator.hpp"

#include <utility>

void Calculator::compute(std::unique_ptr<Command> command)
{
    current_value_ = command->execute(current_value_);
    undo_stack_.push(std::move(command));
    redo_stack_ = {};
}

void Calculator::undo()
{
    if (undo_stack_.empty())
        return;

    auto command = std::move(undo_stack_.top());
    undo_stack_.pop();

    current_value_ = command->undo(current_value_);

    redo_stack_.push(std::move(command));
}

void Calculator::redo()
{
    if (redo_stack_.empty())
        return;

    auto command = std::move(redo_stack_.top());
    redo_stack_.pop();

    current_value_ = command->execute(current_value_);

    undo_stack_.push(std::move(command));
}
