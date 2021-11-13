#include "client_commands.h"

#include <cstdlib>

#include <fmt/core.h>

const Command quit_command = [] {
    fmt::print("QuitCommand\n");
    std::exit(1);
};
