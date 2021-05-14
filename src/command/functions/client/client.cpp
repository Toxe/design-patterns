#include "client.h"

#include <cstdlib>

#include <spdlog/spdlog.h>

#include "client_commands.h"
#include "keyboard_events.h"
#include "receiver/receiver_commands.h"

void Client::setup()
{
    input_handler_.set_command(KeyPressedEvent::Escape, quit_command);
    input_handler_.set_command(KeyPressedEvent::G, PickupGoldCommand(player_));
    input_handler_.set_command(KeyPressedEvent::O, OpenDoorCommand(player_));
    input_handler_.set_command(KeyPressedEvent::Left, MoveLeftCommand(player_));
    input_handler_.set_command(KeyPressedEvent::Right, MoveRightCommand(player_));
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
    input_handler_.event(KeyPressedEvent::Escape);
    input_handler_.event(KeyPressedEvent::Escape);
}
