#pragma once

#include "../shape/circle.hpp"

class JSONCirclePrintStrategy {
public:
    JSONCirclePrintStrategy(const bool pretty_print, const int indent_width = 0)
        : pretty_print_{pretty_print}, indent_width_{indent_width} { }

    std::string operator()(const Circle& circle) const;

private:
    bool pretty_print_;
    int indent_width_;
};
