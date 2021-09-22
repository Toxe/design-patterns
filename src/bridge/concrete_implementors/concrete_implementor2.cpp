#include "concrete_implementor2.h"

#include <fmt/color.h>
#include <fmt/core.h>

void ConcreteImplementor2::print_value(const int value)
{
    fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::yellow), "<{}>", value);
}

void ConcreteImplementor2::print_delimiter()
{
    fmt::print(" ");
}
