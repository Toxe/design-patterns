#pragma once

#include "command.h"
#include "receiver.h"

extern const Command MoveLeftCommand(Receiver& player);
extern const Command MoveRightCommand(Receiver& player);
extern const Command OpenDoorCommand(Receiver& player);
extern const Command PickupGoldCommand(Receiver& player);
