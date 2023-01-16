#pragma once

#include <memory>
#include <utility>

#include "../print_strategy/print_strategy.hpp"
#include "shape.hpp"

class Rectangle : public Shape {
public:
    using RectanglePrintStrategy = PrintStrategy<Rectangle>;

    Rectangle(std::unique_ptr<RectanglePrintStrategy> printer, const int width, const int height)
        : printer_{std::move(printer)}, width_{width}, height_{height} { }

    std::string print() const override { return printer_->print(*this); }

    int width() const { return width_; }
    int height() const { return height_; }

private:
    std::unique_ptr<RectanglePrintStrategy> printer_;

    int width_;
    int height_;
};
