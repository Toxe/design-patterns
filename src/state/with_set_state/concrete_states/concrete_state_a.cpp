#include "concrete_state_a.h"

#include "concrete_state_b.h"
#include "context/context.h"

void ConcreteStateA::request1(Context* context)
{
    context->set_state(std::make_unique<ConcreteStateB>());
}
