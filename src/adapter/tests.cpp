#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "adaptee/adaptee.h"
#include "adapter/adapter.h"
#include "client/client.h"

TEST_CASE("Adapter returns correct value")
{
    Adaptee adaptee;
    Adapter adapter(adaptee);

    const auto value = client(adapter);

    REQUIRE_THAT(value, Catch::Matchers::Equals("Adaptee::specific_request()"));
}
