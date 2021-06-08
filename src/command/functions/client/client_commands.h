#pragma once

#include <cstdlib>

#include <fmt/core.h>

#include "command.h"

Command quit_command = [] {
    fmt::print("QuitCommand\n");
    std::exit(1);
};
