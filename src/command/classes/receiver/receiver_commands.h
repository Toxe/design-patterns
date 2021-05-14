#pragma once

#include <spdlog/spdlog.h>

#include "command.h"
#include "receiver.h"

struct MoveLeftCommand : public Command {
    Receiver& player_;

    MoveLeftCommand(Receiver& player) : player_{player} {}

    void execute() override {
        spdlog::debug("MoveLeftCommand");
        player_.move(-1);
    }
};

struct MoveRightCommand : public Command {
    Receiver& player_;

    MoveRightCommand(Receiver& player) : player_{player} {}

    void execute() override {
        spdlog::debug("MoveRightCommand");
        player_.move(1);
    }
};

struct OpenDoorCommand : public Command {
    Receiver& player_;

    OpenDoorCommand(Receiver& player) : player_{player} {}

    void execute() override {
        spdlog::debug("OpenDoorCommand");
        player_.open_door();
    }
};

struct PickupGoldCommand : public Command {
    Receiver& player_;

    PickupGoldCommand(Receiver& player) : player_{player} {}

    void execute() override {
        spdlog::debug("PickupGoldCommand");
        player_.pickup_gold(10);
    }
};
