#include "concrete_state_a.h"

#include "concrete_state_b.h"

std::unique_ptr<State> ConcreteStateA::request1()
{
    return std::make_unique<ConcreteStateB>();
}
