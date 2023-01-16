#include "simple_rectangle_print_strategy.hpp"

#include "fmt/core.h"

std::string SimpleRectanglePrintStrategy::print(const Rectangle& rectangle)
{
    return fmt::format("Rectangle: width={}, height={}", rectangle.width(), rectangle.height());
}
