#include "client.h"

#include "command.h"
#include "client_commands.h"
#include "keyboard_events.h"
#include "receiver/receiver_commands.h"

void Client::setup()
{
    input_handler_.set_command(KeyPressedEvent::Escape, new QuitCommand());
    input_handler_.set_command(KeyPressedEvent::G, new PickupGoldCommand(player_));
    input_handler_.set_command(KeyPressedEvent::O, new OpenDoorCommand(player_));
    input_handler_.set_command(KeyPressedEvent::Left, new MoveLeftCommand(player_));
    input_handler_.set_command(KeyPressedEvent::Right, new MoveRightCommand(player_));
}

void Client::run()
{
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::Left);
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::Space);
    input_handler_.event(KeyPressedEvent::O);
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::G);
    input_handler_.event(KeyPressedEvent::Right);
    input_handler_.event(KeyPressedEvent::G);
}

void Client::quit()
{
    input_handler_.event(KeyPressedEvent::Escape);
    input_handler_.event(KeyPressedEvent::Escape);
}
