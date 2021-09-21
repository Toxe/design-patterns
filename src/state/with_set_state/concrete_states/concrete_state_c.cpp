#include "concrete_state_c.h"

#include "concrete_state_a.h"
#include "context/context.h"

void ConcreteStateC::request3(Context* context)
{
    context->set_state(std::make_unique<ConcreteStateA>());
}
