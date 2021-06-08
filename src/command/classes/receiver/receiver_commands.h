#pragma once

#include <fmt/core.h>

#include "command.h"
#include "receiver.h"

struct ReceiverCommand : public Command {
    Receiver& player_;

    ReceiverCommand(Receiver& player) : player_{player} {}
};

struct MoveLeftCommand : public ReceiverCommand {
    MoveLeftCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        fmt::print("MoveLeftCommand\n");
        player_.move(-1);
    }
};

struct MoveRightCommand : public ReceiverCommand {
    MoveRightCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        fmt::print("MoveRightCommand\n");
        player_.move(1);
    }
};

struct OpenDoorCommand : public ReceiverCommand {
    OpenDoorCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        fmt::print("OpenDoorCommand\n");
        player_.open_door();
    }
};

struct PickupGoldCommand : public ReceiverCommand {
    PickupGoldCommand(Receiver& player) : ReceiverCommand{player} {}

    void execute() override {
        fmt::print("PickupGoldCommand\n");
        player_.pickup_gold(10);
    }
};
