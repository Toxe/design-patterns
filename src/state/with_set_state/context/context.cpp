#include "context.h"

#include <fmt/core.h>

#include "concrete_states/concrete_state_a.h"
#include "state/state.h"

Context::Context() : state_{std::make_unique<ConcreteStateA>()} { }

void Context::set_state(std::unique_ptr<State> new_state)
{
    fmt::print("transition: {} --> {}\n", state_->name(), new_state->name());

    state_ = std::move(new_state);
}

void Context::request1()
{
    state_->request1(this);
};

void Context::request2()
{
    state_->request2(this);
};

void Context::request3()
{
    state_->request3(this);
};
