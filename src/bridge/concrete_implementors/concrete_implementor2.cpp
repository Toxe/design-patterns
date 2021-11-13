#include "concrete_implementor2.h"

#include <fmt/core.h>

std::string ConcreteImplementor2::print_value(const int value)
{
    return fmt::format("<{}>", value);
}

std::string ConcreteImplementor2::print_delimiter()
{
    return fmt::format(" ");
}
