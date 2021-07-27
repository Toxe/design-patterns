#include "concrete_state_b.h"

#include "concrete_state_c.h"

std::unique_ptr<State> ConcreteStateB::request2()
{
    show_transition_message("request2", "C");
    return std::make_unique<ConcreteStateC>();
}
