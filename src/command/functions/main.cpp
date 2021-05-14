#include "client/client.h"

#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::debug);

    Client client;

    client.setup();
    client.run();
}
