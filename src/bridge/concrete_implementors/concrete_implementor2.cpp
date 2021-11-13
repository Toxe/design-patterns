#include "concrete_implementor2.h"

#include <fmt/core.h>

void ConcreteImplementor2::print_value(const int value)
{
    fmt::print("<{}>", value);
}

void ConcreteImplementor2::print_delimiter()
{
    fmt::print(" ");
}
