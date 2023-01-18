#pragma once

#include <string>

template <typename T>
class PrintStrategy {
public:
    virtual ~PrintStrategy() = default;
    virtual std::string print(const T&) const = 0;
};
