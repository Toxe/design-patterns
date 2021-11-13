#pragma once

#include "invoker/invoker.h"
#include "receiver/receiver.h"

class Client {
    Invoker input_handler_;
    Receiver player_;

public:
    void setup();
    void run();
    void quit();

    [[nodiscard]] int player_gold() const { return player_.gold(); }
    [[nodiscard]] int player_position() const { return player_.position(); }
};
