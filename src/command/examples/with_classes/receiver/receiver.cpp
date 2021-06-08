#include "receiver.h"

#include <fmt/core.h>

void Receiver::move(int delta_x)
{
    if (posx_ + delta_x >= 0) {
        posx_ += delta_x;
        fmt::print("player moved to {}\n", posx_);
    } else {
        fmt::print("player cannot move in that direction\n");
    }
}

void Receiver::open_door()
{
    fmt::print("player opened door\n");
}

void Receiver::pickup_gold(int amount)
{
    if (amount > 0) {
        gold_ += amount;
        fmt::print("player picked up {} gold\n", amount);
    }
}
