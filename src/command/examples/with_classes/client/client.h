#pragma once

#include "invoker/invoker.h"
#include "receiver/receiver.h"

class Client {
    Invoker input_handler_;
    Receiver player_;

public:
    void setup();
    void run();
};
