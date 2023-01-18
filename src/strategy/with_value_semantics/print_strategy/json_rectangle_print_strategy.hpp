#pragma once

#include "../shape/rectangle.hpp"

class JSONRectanglePrintStrategy {
public:
    JSONRectanglePrintStrategy(const bool pretty_print, const int indent_width = 0)
        : pretty_print_{pretty_print}, indent_width_{indent_width} { }

    std::string operator()(const Rectangle& circle) const;

private:
    bool pretty_print_;
    int indent_width_;
};
