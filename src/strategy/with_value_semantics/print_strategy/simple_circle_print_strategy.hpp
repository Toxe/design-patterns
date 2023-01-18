#pragma once

#include "../shape/circle.hpp"

class SimpleCirclePrintStrategy {
public:
    explicit SimpleCirclePrintStrategy(const bool show_properties)
        : show_properties_{show_properties} { }

    std::string operator()(const Circle& circle) const;

private:
    bool show_properties_;
};
