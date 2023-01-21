#pragma once

#include <functional>

struct Command {
    std::function<int(int)> execute;
    std::function<int(int)> undo;
};
