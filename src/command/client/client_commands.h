#pragma once

#include <cstdlib>

#include <spdlog/spdlog.h>

#include "command.h"

struct QuitCommand : public Command {
    void execute() override {
        spdlog::debug("QuitCommand");
        std::exit(1);
    }
};
