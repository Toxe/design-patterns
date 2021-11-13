#include "catch2/catch_test_macros.hpp"

#include "client/client.h"

TEST_CASE("Client works")
{
    Client client;

    client.setup();
    client.run();

    REQUIRE(client.player_gold() == 20);
    REQUIRE(client.player_position() == 5);
}
