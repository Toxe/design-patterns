#pragma once

#include "../shape/rectangle.hpp"
#include "print_strategy.hpp"

class JSONRectanglePrintStrategy : public PrintStrategy<Rectangle> {
public:
    JSONRectanglePrintStrategy(const bool pretty_print, const int indent_width = 0)
        : pretty_print_{pretty_print}, indent_width_{indent_width} { }

    std::string print(const Rectangle& rectangle) override;

private:
    bool pretty_print_;
    int indent_width_;
};
