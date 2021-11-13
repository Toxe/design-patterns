#pragma once

#include <string>

class Target {
public:
    virtual std::string request() = 0;
};
