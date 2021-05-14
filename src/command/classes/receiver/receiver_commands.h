#pragma once

#include <spdlog/spdlog.h>

#include "command.h"
#include "receiver.h"

struct ReceiverCommand : public Command {
    Receiver& player_;

    ReceiverCommand(Receiver& player) : player_{player} {}
};

struct MoveLeftCommand : public ReceiverCommand {
    MoveLeftCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        spdlog::debug("MoveLeftCommand");
        player_.move(-1);
    }
};

struct MoveRightCommand : public ReceiverCommand {
    MoveRightCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        spdlog::debug("MoveRightCommand");
        player_.move(1);
    }
};

struct OpenDoorCommand : public ReceiverCommand {
    OpenDoorCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        spdlog::debug("OpenDoorCommand");
        player_.open_door();
    }
};

struct PickupGoldCommand : public ReceiverCommand {
    PickupGoldCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        spdlog::debug("PickupGoldCommand");
        player_.pickup_gold(10);
    }
};
