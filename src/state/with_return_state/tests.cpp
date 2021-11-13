#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "context/context.h"

TEST_CASE("Client returns correct values")
{
    Context context;

    REQUIRE_THAT(context.request1(), Catch::Matchers::Equals("State B"));
    REQUIRE_THAT(context.request1(), Catch::Matchers::Equals("State B"));
    REQUIRE_THAT(context.request2(), Catch::Matchers::Equals("State C"));
    REQUIRE_THAT(context.request2(), Catch::Matchers::Equals("State C"));
    REQUIRE_THAT(context.request3(), Catch::Matchers::Equals("State A"));
}
