#pragma once

#include <spdlog/spdlog.h>

#include "command.h"
#include "receiver.h"

Command MoveLeftCommand(Receiver& player)
{
    return [&] {
        spdlog::debug("MoveLeftCommand");
        player.move(-1);
    };
}

Command MoveRightCommand(Receiver& player)
{
    return [&] {
        spdlog::debug("MoveRightCommand");
        player.move(1);
    };
}

Command OpenDoorCommand(Receiver& player)
{
    return [&] {
        spdlog::debug("OpenDoorCommand");
        player.open_door();
    };
}

Command PickupGoldCommand(Receiver& player)
{
    return [&] {
        spdlog::debug("PickupGoldCommand");
        player.pickup_gold(10);
    };
}
