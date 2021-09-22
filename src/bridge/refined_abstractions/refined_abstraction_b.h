#pragma once

#include "abstraction/abstraction.h"
#include "implementor/implementor.h"

class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(std::vector<int> values, Implementor& imp) : Abstraction{values, imp} { }

    virtual void print_values() override;
};
