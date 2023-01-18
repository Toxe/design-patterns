#include "simple_circle_print_strategy.hpp"

#include "fmt/core.h"

std::string SimpleCirclePrintStrategy::operator()(const Circle& circle) const
{
    if (show_properties_)
        return fmt::format("[Circle] {}: radius={}", circle.name(), circle.radius());

    return fmt::format("[Circle] {}", circle.name());
}
