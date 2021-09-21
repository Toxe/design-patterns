#include "concrete_state_b.h"

#include "concrete_state_c.h"
#include "context/context.h"

void ConcreteStateB::request2(Context* context)
{
    context->set_state(std::make_unique<ConcreteStateC>());
}
