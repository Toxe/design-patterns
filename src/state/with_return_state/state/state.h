#pragma once

#include <memory>

class State {
    const char* name_;

protected:
    void show_unhandled_request_message(const char* request);

public:
    State(const char* name) : name_{name} {}

    virtual ~State() = default;

    [[nodiscard]] const char* name() const { return name_; };

    virtual std::unique_ptr<State> request1();
    virtual std::unique_ptr<State> request2();
    virtual std::unique_ptr<State> request3();
};
