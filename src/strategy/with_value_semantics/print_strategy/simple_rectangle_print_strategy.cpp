#include "simple_rectangle_print_strategy.hpp"

#include "fmt/core.h"

std::string SimpleRectanglePrintStrategy::operator()(const Rectangle& rectangle) const
{
    if (show_properties_)
        return fmt::format("[Rectangle] {}: width={}, height={}", rectangle.name(), rectangle.width(), rectangle.height());

    return fmt::format("[Rectangle] {}", rectangle.name());
}
