#pragma once

class AbstractProductA {
public:
    [[nodiscard]] virtual const char* name() = 0;

    virtual ~AbstractProductA() = default;
};
