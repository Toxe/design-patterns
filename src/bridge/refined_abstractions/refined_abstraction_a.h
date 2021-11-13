#pragma once

#include "abstraction/abstraction.h"
#include "implementor/implementor.h"

class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(std::vector<int> values, Implementor& imp) : Abstraction{values, imp} { }

    virtual std::string print_values() override;
};
