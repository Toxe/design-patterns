#include "concrete_implementor1.h"

#include <fmt/color.h>
#include <fmt/core.h>

void ConcreteImplementor1::print_value(const int value)
{
    fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::orange), "{}", value);
}

void ConcreteImplementor1::print_delimiter()
{
    fmt::print(", ");
}
