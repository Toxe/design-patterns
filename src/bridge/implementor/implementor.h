#pragma once

#include <string>

class Implementor {
public:
    virtual std::string print_value(const int value) = 0;
    virtual std::string print_delimiter() = 0;
};