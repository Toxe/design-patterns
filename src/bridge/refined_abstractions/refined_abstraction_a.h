#pragma once

#include "abstraction/abstraction.h"
#include "implementor/implementor.h"

class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(std::vector<int> values, Implementor& imp) : Abstraction{values, imp} { }

    virtual void print_values() override;
};
