#include "concrete_implementor1.h"

#include <fmt/core.h>

void ConcreteImplementor1::print_value(const int value)
{
    fmt::print("{}", value);
}

void ConcreteImplementor1::print_delimiter()
{
    fmt::print(", ");
}
