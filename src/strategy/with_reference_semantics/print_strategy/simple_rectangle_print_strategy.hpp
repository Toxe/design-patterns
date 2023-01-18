#pragma once

#include "../shape/rectangle.hpp"
#include "print_strategy.hpp"

class SimpleRectanglePrintStrategy : public PrintStrategy<Rectangle> {
public:
    explicit SimpleRectanglePrintStrategy(const bool show_properties) : show_properties_{show_properties} { }

    std::string print(const Rectangle& rectangle) const override;

private:
    bool show_properties_;
};
