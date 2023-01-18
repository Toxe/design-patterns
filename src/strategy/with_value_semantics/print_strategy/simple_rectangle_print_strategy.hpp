#pragma once

#include "../shape/rectangle.hpp"

class SimpleRectanglePrintStrategy {
public:
    explicit SimpleRectanglePrintStrategy(const bool show_properties)
        : show_properties_{show_properties} { }

    std::string operator()(const Rectangle& circle) const;

private:
    bool show_properties_;
};
