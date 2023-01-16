#pragma once

#include "../shape/rectangle.hpp"
#include "print_strategy.hpp"

class SimpleRectanglePrintStrategy : public PrintStrategy<Rectangle> {
public:
    std::string print(const Rectangle& rectangle) override;
};
