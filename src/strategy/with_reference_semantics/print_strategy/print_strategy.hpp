#pragma once

#include <string>

template <typename T>
class PrintStrategy {
public:
    virtual std::string print(const T&) = 0;
};
