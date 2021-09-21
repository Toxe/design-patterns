#pragma once

#include "adaptee/adaptee.h"
#include "target/target.h"

class Adapter : public Target {
    Adaptee& adaptee_;

public:
    Adapter(Adaptee& adaptee) : adaptee_{adaptee} { }

    virtual void request() override;
};