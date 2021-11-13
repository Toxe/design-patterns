#pragma once

#include "implementor/implementor.h"

class ConcreteImplementor1 : public Implementor {
public:
    virtual std::string print_value(const int value) override;
    virtual std::string print_delimiter() override;
};
