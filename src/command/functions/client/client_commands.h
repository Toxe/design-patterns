#pragma once

#include <cstdlib>

#include <spdlog/spdlog.h>

#include "command.h"

Command quit_command = [] {
    spdlog::debug("QuitCommand");
    std::exit(1);
};
