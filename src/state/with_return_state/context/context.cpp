#include "context.h"

#include <fmt/core.h>

#include "concrete_states/concrete_state_a.h"
#include "state/state.h"

Context::Context() : state_{std::make_unique<ConcreteStateA>()} { }

void Context::update_state(std::unique_ptr<State> next_state)
{
    if (next_state) {
        fmt::print("transition: {} --> {}\n", state_->name(), next_state->name());
        state_ = std::move(next_state);
    }
}

std::string Context::request1()
{
    update_state(state_->request1());
    return state_->name();
}

std::string Context::request2()
{
    update_state(state_->request2());
    return state_->name();
}

std::string Context::request3()
{
    update_state(state_->request3());
    return state_->name();
}
