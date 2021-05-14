#pragma once

#include <spdlog/spdlog.h>

struct Command {
    virtual ~Command() = default;
    virtual void execute() = 0;
};

struct NoCommand : public Command {
    void execute() override {
        spdlog::debug("NoCommand");
    }
};
