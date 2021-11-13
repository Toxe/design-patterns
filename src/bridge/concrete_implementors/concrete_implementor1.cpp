#include "concrete_implementor1.h"

#include <fmt/core.h>

std::string ConcreteImplementor1::print_value(const int value)
{
    return fmt::format("{}", value);
}

std::string ConcreteImplementor1::print_delimiter()
{
    return fmt::format(", ");
}
