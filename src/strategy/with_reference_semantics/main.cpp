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

    shapes.emplace_back(std::make_unique<Circle>("circle 1", 3, std::make_unique<SimpleCirclePrintStrategy>(true)));
    shapes.emplace_back(std::make_unique<Circle>("circle 2", 5, std::make_unique<SimpleCirclePrintStrategy>(false)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 1", 7, 3, std::make_unique<SimpleRectanglePrintStrategy>(true)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 2", 2, 4, std::make_unique<SimpleRectanglePrintStrategy>(false)));

    shapes.emplace_back(std::make_unique<Circle>("circle 3", 5, std::make_unique<JSONCirclePrintStrategy>(false)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 3", 2, 4, std::make_unique<JSONRectanglePrintStrategy>(false)));
    shapes.emplace_back(std::make_unique<Circle>("circle 4", 3, std::make_unique<JSONCirclePrintStrategy>(true, 4)));
    shapes.emplace_back(std::make_unique<Rectangle>("rectangle 4", 7, 3, std::make_unique<JSONRectanglePrintStrategy>(true, 4)));

    for (const auto& shape : shapes)
        fmt::print("{}\n", shape->print());
}
