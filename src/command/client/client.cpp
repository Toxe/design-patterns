#include "client.h"

#include "command.h"
#include "client_commands.h"
#include "keyboard_events.h"
#include "receiver/receiver_commands.h"

void Client::setup()
{
    QuitCommand* quit_command = new QuitCommand();
    MoveLeftCommand* move_left_command = new MoveLeftCommand(player_);
    MoveRightCommand* move_right_command = new MoveRightCommand(player_);
    OpenDoorCommand* open_door_command = new OpenDoorCommand(player_);
    PickupGoldCommand* pickup_gold_command = new PickupGoldCommand(player_);

    input_handler_.set_command(KeyPressedEvent::G, pickup_gold_command);
    input_handler_.set_command(KeyPressedEvent::O, open_door_command);
    input_handler_.set_command(KeyPressedEvent::Escape, quit_command);
    input_handler_.set_command(KeyPressedEvent::Left, move_left_command);
    input_handler_.set_command(KeyPressedEvent::Right, move_right_command);
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
