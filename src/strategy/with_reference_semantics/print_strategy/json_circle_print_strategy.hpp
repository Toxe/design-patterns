#pragma once

#include "../shape/circle.hpp"
#include "print_strategy.hpp"

class JSONCirclePrintStrategy : public PrintStrategy<Circle> {
public:
    JSONCirclePrintStrategy(const bool pretty_print, const int indent_width = 0)
        : pretty_print_{pretty_print}, indent_width_{indent_width} { }

    std::string print(const Circle& circle) override;

private:
    bool pretty_print_;
    int indent_width_;
};
