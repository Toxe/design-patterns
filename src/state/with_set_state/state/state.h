#pragma once

class Context;

class State {
    const char* name_;

protected:
    void show_unhandled_request_message(const char* request);
    void show_transition_message(const char* request, const char* next_state);

public:
    State(const char* name) : name_{name} {}

    virtual ~State() = default;

    virtual void request1(Context*) { show_unhandled_request_message("request1"); };
    virtual void request2(Context*) { show_unhandled_request_message("request2"); };
    virtual void request3(Context*) { show_unhandled_request_message("request3"); };
};
