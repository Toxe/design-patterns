#pragma once

#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    virtual std::string print() const = 0;
};
