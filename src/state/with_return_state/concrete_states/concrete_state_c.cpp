#include "concrete_state_c.h"

#include "concrete_state_a.h"

std::unique_ptr<State> ConcreteStateC::request3()
{
    show_transition_message("request3", "A");
    return std::make_unique<ConcreteStateA>();
}
