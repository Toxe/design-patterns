#include "invoker.h"

#include <stdexcept>

Invoker::Invoker()
{
    commands_[KeyPressedEvent::G]      = new NoCommand{};
    commands_[KeyPressedEvent::O]      = new NoCommand{};
    commands_[KeyPressedEvent::Escape] = new NoCommand{};
    commands_[KeyPressedEvent::Left]   = new NoCommand{};
    commands_[KeyPressedEvent::Right]  = new NoCommand{};
    commands_[KeyPressedEvent::Space]  = new NoCommand{};
}

void Invoker::set_command(const KeyPressedEvent& key_event, Command* command)
{
    commands_[key_event] = command;
}

void Invoker::event(const KeyPressedEvent& key_event)
{
    commands_[key_event]->execute();
}
