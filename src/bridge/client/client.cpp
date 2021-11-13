#include "client.h"

#include "abstraction/abstraction.h"

std::string client(Abstraction& abstraction)
{
    return abstraction.print_values();
}
