#pragma once

#include <string>
#include <vector>

class Implementor;

class Abstraction {
    std::vector<int> values_;
    Implementor& imp_;

public:
    Abstraction(std::vector<int> values, Implementor& imp) : values_{values}, imp_{imp} { }
    virtual ~Abstraction() = default;

    virtual std::string print_values();

protected:
    Implementor& imp() { return imp_; };
    const std::vector<int>& values() { return values_; };
};
