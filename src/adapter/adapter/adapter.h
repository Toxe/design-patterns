#pragma once

#include "target/target.h"

class Adaptee;

class Adapter : public Target {
    Adaptee& adaptee_;

public:
    Adapter(Adaptee& adaptee) : adaptee_{adaptee} { }

    std::string request() override;
};