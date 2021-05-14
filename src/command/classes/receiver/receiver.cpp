#include "receiver.h"

#include <spdlog/spdlog.h>

void Receiver::move(int delta_x)
{
    if (posx_ + delta_x >= 0) {
        posx_ += delta_x;
        spdlog::info("player moved to {}", posx_);
    } else {
        spdlog::debug("player cannot move in that direction");
    }
}

void Receiver::open_door()
{
    spdlog::info("player opened door");
}

void Receiver::pickup_gold(int amount)
{
    if (amount > 0) {
        gold_ += amount;
        spdlog::info("player picked up {} gold", amount);
    }
}
