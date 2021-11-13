#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "client/client.h"
#include "concrete_implementors/concrete_implementor1.h"
#include "concrete_implementors/concrete_implementor2.h"
#include "refined_abstractions/refined_abstraction_a.h"
#include "refined_abstractions/refined_abstraction_b.h"

TEST_CASE("Client returns correct values")
{
    ConcreteImplementor1 concrete_implementor1;
    ConcreteImplementor2 concrete_implementor2;

    RefinedAbstractionA refined_abstraction_a1{{1, 2, 3, 4, 5}, concrete_implementor1};
    RefinedAbstractionA refined_abstraction_a2{{1, 2, 3, 4, 5}, concrete_implementor2};
    RefinedAbstractionB refined_abstraction_b1{{1, 2, 3, 4, 5}, concrete_implementor1};
    RefinedAbstractionB refined_abstraction_b2{{1, 2, 3, 4, 5}, concrete_implementor2};

    REQUIRE_THAT(client(refined_abstraction_a1), Catch::Matchers::Equals("1, 2, 3, 4, 5, "));
    REQUIRE_THAT(client(refined_abstraction_a2), Catch::Matchers::Equals("<1> <2> <3> <4> <5> "));
    REQUIRE_THAT(client(refined_abstraction_b1), Catch::Matchers::Equals("value #1 = 1, value #2 = 2, value #3 = 3, value #4 = 4, value #5 = 5, "));
    REQUIRE_THAT(client(refined_abstraction_b2), Catch::Matchers::Equals("value #1 = <1> value #2 = <2> value #3 = <3> value #4 = <4> value #5 = <5> "));
}
