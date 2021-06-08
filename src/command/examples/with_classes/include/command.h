#pragma once

#include <fmt/core.h>

struct Command {
    virtual ~Command() = default;
    virtual void execute() = 0;
};

struct NoCommand : public Command {
    void execute() override {
        fmt::print("NoCommand\n");
    }
};
