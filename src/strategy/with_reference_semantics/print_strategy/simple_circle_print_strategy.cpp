#include "simple_circle_print_strategy.hpp"

#include "fmt/core.h"

std::string SimpleCirclePrintStrategy::print(const Circle& circle)
{
    if (show_properties_)
        return fmt::format("[Circle] {}: radius={}", circle.name(), circle.radius());

    return fmt::format("[Circle] {}", circle.name());
}
