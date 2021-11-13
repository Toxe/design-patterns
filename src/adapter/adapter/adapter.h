#pragma once

#include "target/target.h"

class Adaptee;

class Adapter : public Target {
    Adaptee& adaptee_;

public:
    Adapter(Adaptee& adaptee) : adaptee_{adaptee} { }
    virtual ~Adapter() = default;

    virtual std::string request() override;
};