#pragma once

class Implementor {
public:
    virtual void print_value(const int value) = 0;
    virtual void print_delimiter() = 0;
};