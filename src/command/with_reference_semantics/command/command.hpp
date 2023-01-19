#pragma once

class Command {
public:
    virtual ~Command() = default;

    virtual int execute(int current) const = 0;
    virtual int undo(int current) const = 0;
};
