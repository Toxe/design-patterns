#include "concrete_state_a.h"

#include "concrete_state_b.h"
#include "context/context.h"

void ConcreteStateA::request1(Context* context)
{
    show_transition_message("request1", "B");
    context->change_state(std::make_unique<ConcreteStateB>());
}
