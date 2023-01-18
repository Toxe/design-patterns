#pragma once

#include "../shape/circle.hpp"
#include "print_strategy.hpp"

class SimpleCirclePrintStrategy : public PrintStrategy<Circle> {
public:
    explicit SimpleCirclePrintStrategy(const bool show_properties)
        : show_properties_{show_properties} { }

    std::string print(const Circle& circle) const override;

private:
    bool show_properties_;
};
