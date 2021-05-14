#include "invoker.h"

#include <stdexcept>

Invoker::Invoker()
{
    commands_[KeyPressedEvent::G]      = std::make_unique<NoCommand>();
    commands_[KeyPressedEvent::O]      = std::make_unique<NoCommand>();
    commands_[KeyPressedEvent::Escape] = std::make_unique<NoCommand>();
    commands_[KeyPressedEvent::Left]   = std::make_unique<NoCommand>();
    commands_[KeyPressedEvent::Right]  = std::make_unique<NoCommand>();
    commands_[KeyPressedEvent::Space]  = std::make_unique<NoCommand>();
}

void Invoker::set_command(const KeyPressedEvent& key_event, Command* command)
{
    commands_[key_event].reset(command);
}

void Invoker::event(const KeyPressedEvent& key_event)
{
    commands_[key_event]->execute();
}
