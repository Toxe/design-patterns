#pragma once

class Receiver {
    int posx_ = 0;
    int gold_ = 0;

public:
    void move(int delta_x);
    void open_door();
    void pickup_gold(int amount);
};
