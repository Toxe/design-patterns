#include "simple_circle_print_strategy.hpp"

#include "fmt/core.h"

std::string SimpleCirclePrintStrategy::print(const Circle& circle)
{
    return fmt::format("Circle: radius={}", circle.radius());
}
