#pragma once

#include <fmt/core.h>

#include "command.h"
#include "receiver.h"

Command MoveLeftCommand(Receiver& player)
{
    return [&] {
        fmt::print("MoveLeftCommand\n");
        player.move(-1);
    };
}

Command MoveRightCommand(Receiver& player)
{
    return [&] {
        fmt::print("MoveRightCommand\n");
        player.move(1);
    };
}

Command OpenDoorCommand(Receiver& player)
{
    return [&] {
        fmt::print("OpenDoorCommand\n");
        player.open_door();
    };
}

Command PickupGoldCommand(Receiver& player)
{
    return [&] {
        fmt::print("PickupGoldCommand\n");
        player.pickup_gold(10);
    };
}
