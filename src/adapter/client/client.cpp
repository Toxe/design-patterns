#include "client.h"

#include "target/target.h"

std::string client(Target& target)
{
    return target.request();
}
