#include "state.h"

#include <fmt/core.h>

void State::show_unhandled_request_message(const char* request)
{
    fmt::print("[{}, {}] the current state does not handle {}\n", name_, request, request);
}

void State::show_transition_message(const char* request, const char* next_state)
{
    fmt::print("[{}, {}] changing to state {}\n", name_, request, next_state);
}
