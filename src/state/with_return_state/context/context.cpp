#include "context.h"

#include "concrete_states/concrete_state_a.h"
#include "state/state.h"

Context::Context() : state_{std::make_unique<ConcreteStateA>()} { }

void Context::update_state(std::unique_ptr<State> next_state)
{
    if (next_state)
        state_ = std::move(next_state);
}

void Context::request1()
{
    update_state(state_->request1());
};

void Context::request2()
{
    update_state(state_->request2());
};

void Context::request3()
{
    update_state(state_->request3());
};
