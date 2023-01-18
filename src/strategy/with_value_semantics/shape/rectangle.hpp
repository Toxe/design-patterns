#pragma once

#include <functional>
#include <utility>

#include "shape.hpp"

class Rectangle : public Shape {
public:
    using RectanglePrintStrategy = std::function<std::string(const Rectangle&)>;

    Rectangle(const char* name, const int width, const int height, RectanglePrintStrategy printer)
        : Shape{name}, printer_{std::move(printer)}, width_{width}, height_{height} { }

    std::string print() const override { return printer_(*this); }

    int width() const { return width_; }
    int height() const { return height_; }

private:
    RectanglePrintStrategy printer_;

    int width_;
    int height_;
};
