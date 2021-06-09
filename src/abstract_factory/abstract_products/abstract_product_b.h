#pragma once

class AbstractProductB {
public:
    [[nodiscard]] virtual const char* name() = 0;

    virtual ~AbstractProductB() = default;
};
