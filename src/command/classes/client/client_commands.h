#pragma once

#include <cstdlib>

#include <fmt/core.h>

#include "command.h"

struct QuitCommand : public Command {
    void execute() override {
        fmt::print("QuitCommand\n");
        std::exit(1);
    }
};
