#include <memory>
#include <vector>

#include "fmt/core.h"

#include "print_strategy/json_circle_print_strategy.hpp"
#include "print_strategy/json_rectangle_print_strategy.hpp"
#include "print_strategy/simple_circle_print_strategy.hpp"
#include "print_strategy/simple_rectangle_print_strategy.hpp"
#include "shape/circle.hpp"
#include "shape/rectangle.hpp"

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<SimpleCirclePrintStrategy>(), 5));
    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<SimpleCirclePrintStrategy>(), 3));
    shapes.emplace_back(std::make_unique<Rectangle>(std::make_unique<SimpleRectanglePrintStrategy>(), 2, 4));
    shapes.emplace_back(std::make_unique<Rectangle>(std::make_unique<SimpleRectanglePrintStrategy>(), 7, 3));

    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<JSONCirclePrintStrategy>(), 5));
    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<JSONCirclePrintStrategy>(), 3));
    shapes.emplace_back(std::make_unique<Rectangle>(std::make_unique<JSONRectanglePrintStrategy>(), 2, 4));
    shapes.emplace_back(std::make_unique<Rectangle>(std::make_unique<JSONRectanglePrintStrategy>(), 7, 3));

    for (const auto& shape : shapes)
        fmt::print("{}\n", shape->print());
}
