#include "state.h"

#include <fmt/core.h>

void State::show_unhandled_request_message(const char* request)
{
    fmt::print("{} does not handle {}\n", name_, request);
}

std::unique_ptr<State> State::request1()
{
    show_unhandled_request_message("request1");
    return nullptr;
};

std::unique_ptr<State> State::request2()
{
    show_unhandled_request_message("request2");
    return nullptr;
};

std::unique_ptr<State> State::request3()
{
    show_unhandled_request_message("request3");
    return nullptr;
};
