#pragma once

#include <unordered_map>

#include "command.h"
#include "keyboard_events.h"

class Invoker {
    std::unordered_map<KeyPressedEvent, Command> commands_;

public:
    Invoker();

    void set_command(const KeyPressedEvent& key_event, Command command);
    void event(const KeyPressedEvent& key_event);
};
