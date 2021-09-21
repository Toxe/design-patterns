#include "concrete_state_c.h"

#include "concrete_state_a.h"

std::unique_ptr<State> ConcreteStateC::request3()
{
    return std::make_unique<ConcreteStateA>();
}
