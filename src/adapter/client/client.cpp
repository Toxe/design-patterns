#include "client.h"

#include "target/target.h"

void client(Target& target)
{
    target.request();
}
