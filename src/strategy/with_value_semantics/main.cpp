#include <memory>
#include <vector>

#include "fmt/core.h"

#include "print_strategy/json_circle_print_strategy.hpp"
#include "print_strategy/json_rectangle_print_strategy.hpp"
#include "print_strategy/simple_circle_print_strategy.hpp"
#include "print_strategy/simple_rectangle_print_strategy.hpp"
#include "shape/circle.hpp"
#include "shape/rectangle.hpp"

std::string print_rectangle_with_free_function(const Rectangle& rectangle)
{
    return fmt::format("print \"{}\" with free function", rectangle.name());
}

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.emplace_back(std::make_unique<Circle>("circle 1", 3, SimpleCirclePrintStrategy(true)));
    shapes.emplace_back(std::make_unique<Circle>("circle 2", 5, SimpleCirclePrintStrategy(false)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 1", 7, 3, SimpleRectanglePrintStrategy(true)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 2", 2, 4, SimpleRectanglePrintStrategy(false)));

    shapes.emplace_back(std::make_unique<Circle>("circle 3", 5, JSONCirclePrintStrategy(false)));
    shapes.emplace_back(std::make_unique<Circle>("circle 4", 3, JSONCirclePrintStrategy(true, 4)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 3", 2, 4, JSONRectanglePrintStrategy(false)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 4", 7, 3, JSONRectanglePrintStrategy(true, 4)));

    // free functions and lambdas
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 5", 3, 5, print_rectangle_with_free_function));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 6", 3, 5, [](const Rectangle& rectangle) { return fmt::format("print \"{}\" with lambda", rectangle.name()); }));

    for (const auto& shape : shapes)
        fmt::print("{}\n", shape->print());
}
