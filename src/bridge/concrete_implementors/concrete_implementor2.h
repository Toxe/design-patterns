#pragma once

#include "implementor/implementor.h"

class ConcreteImplementor2 : public Implementor {
public:
    std::string print_value(const int value) override;
    std::string print_delimiter() override;
};
