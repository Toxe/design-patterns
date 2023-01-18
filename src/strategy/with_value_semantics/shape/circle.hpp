#pragma once

#include <functional>
#include <utility>

#include "shape.hpp"

class Circle : public Shape {
public:
    using CirclePrintStrategy = std::function<std::string(const Circle&)>;

    Circle(const char* name, const int radius, CirclePrintStrategy printer)
        : Shape{name}, printer_{std::move(printer)}, radius_{radius} { }

    std::string print() const override { return printer_(*this); }

    int radius() const { return radius_; }

private:
    CirclePrintStrategy printer_;

    int radius_;
};
