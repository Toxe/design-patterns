#pragma once

#include <memory>
#include <utility>

#include "../print_strategy/print_strategy.hpp"
#include "shape.hpp"

class Circle : public Shape {
public:
    using CirclePrintStrategy = PrintStrategy<Circle>;

    Circle(const char* name, const int radius, std::unique_ptr<CirclePrintStrategy> printer)
        : Shape{name}, printer_{std::move(printer)}, radius_{radius} { }

    std::string print() const override { return printer_->print(*this); }

    int radius() const { return radius_; }

private:
    std::unique_ptr<CirclePrintStrategy> printer_;

    int radius_;
};
