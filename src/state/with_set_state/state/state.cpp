#include "state.h"

#include <fmt/core.h>

void State::show_unhandled_request_message(const char* request)
{
    fmt::print("{} does not handle {}\n", name_, request);
}
