#include "receiver_commands.h"

#include <fmt/core.h>

const Command MoveLeftCommand(Receiver& player)
{
    return [&] {
        fmt::print("MoveLeftCommand\n");
        player.move(-1);
    };
}

const Command MoveRightCommand(Receiver& player)
{
    return [&] {
        fmt::print("MoveRightCommand\n");
        player.move(1);
    };
}

const Command OpenDoorCommand(Receiver& player)
{
    return [&] {
        fmt::print("OpenDoorCommand\n");
        player.open_door();
    };
}

const Command PickupGoldCommand(Receiver& player)
{
    return [&] {
        fmt::print("PickupGoldCommand\n");
        player.pickup_gold(10);
    };
}
