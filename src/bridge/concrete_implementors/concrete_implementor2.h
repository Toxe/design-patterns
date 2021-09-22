#pragma once

#include "implementor/implementor.h"

class ConcreteImplementor2 : public Implementor {
public:
    virtual void print_value(const int value) override;
    virtual void print_delimiter() override;
};
