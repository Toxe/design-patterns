#pragma once

#include <string>

class Shape {
public:
    explicit Shape(const char* name) : name_{name} { }
    virtual ~Shape() = default;

    const char* name() const { return name_; }

    virtual std::string print() const = 0;

private:
    const char* name_;
};
