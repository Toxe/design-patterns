#include "invoker.h"

#include <fmt/core.h>

Command no_command = [] { fmt::print("NoCommand\n"); };

Invoker::Invoker()
{
    commands_[KeyPressedEvent::G]      = no_command;
    commands_[KeyPressedEvent::O]      = no_command;
    commands_[KeyPressedEvent::Escape] = no_command;
    commands_[KeyPressedEvent::Left]   = no_command;
    commands_[KeyPressedEvent::Right]  = no_command;
    commands_[KeyPressedEvent::Space]  = no_command;
}

void Invoker::set_command(const KeyPressedEvent& key_event, Command command)
{
    commands_[key_event] = command;
}

void Invoker::event(const KeyPressedEvent& key_event)
{
    commands_[key_event]();
}
