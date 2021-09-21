#pragma once

#include <memory>

class State {
    const char* name_;

protected:
    void show_unhandled_request_message(const char* request);
    void show_transition_message(const char* request, const char* next_state);

public:
    State(const char* name) : name_{name} {}

    virtual ~State() = default;

    const char* name() const { return name_; };

    virtual std::unique_ptr<State> request1();
    virtual std::unique_ptr<State> request2();
    virtual std::unique_ptr<State> request3();
};
