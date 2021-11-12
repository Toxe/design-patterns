#pragma once

class Context;

class State {
    const char* name_;

protected:
    void show_unhandled_request_message(const char* request);

public:
    State(const char* name) : name_{name} {}

    virtual ~State() = default;

    [[nodiscard]] const char* name() const { return name_; };

    virtual void request1(Context*) { show_unhandled_request_message("request1"); };
    virtual void request2(Context*) { show_unhandled_request_message("request2"); };
    virtual void request3(Context*) { show_unhandled_request_message("request3"); };
};
