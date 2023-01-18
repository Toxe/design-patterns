#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"
#include "fmt/core.h"

#include "print_strategy/json_circle_print_strategy.hpp"
#include "print_strategy/json_rectangle_print_strategy.hpp"
#include "print_strategy/simple_circle_print_strategy.hpp"
#include "print_strategy/simple_rectangle_print_strategy.hpp"
#include "shape/circle.hpp"
#include "shape/rectangle.hpp"

TEST_CASE("Simple")
{
    SECTION("can print circles")
    {
        const Circle circle1{"circle 1", 3, SimpleCirclePrintStrategy(true)};
        const Circle circle2{"circle 2", 7, SimpleCirclePrintStrategy(false)};

        CHECK_THAT(circle1.print(), Catch::Matchers::Equals("[Circle] circle 1: radius=3"));
        CHECK_THAT(circle2.print(), Catch::Matchers::Equals("[Circle] circle 2"));
    }

    SECTION("can print rectangles")
    {
        const Rectangle rect1{"rectangle 1", 3, 5, SimpleRectanglePrintStrategy(true)};
        const Rectangle rect2{"rectangle 2", 6, 2, SimpleRectanglePrintStrategy(false)};

        CHECK_THAT(rect1.print(), Catch::Matchers::Equals("[Rectangle] rectangle 1: width=3, height=5"));
        CHECK_THAT(rect2.print(), Catch::Matchers::Equals("[Rectangle] rectangle 2"));
    }
}

TEST_CASE("JSON")
{
    SECTION("can print circles")
    {
        const Circle circle1{"circle 1", 3, JSONCirclePrintStrategy(false)};
        const Circle circle2{"circle 2", 7, JSONCirclePrintStrategy(true, 4)};

        CHECK_THAT(circle1.print(), Catch::Matchers::Equals(R"({"name":"circle 1","properties":{"radius":3},"shape":"Circle"})"));
        CHECK_THAT(circle2.print(), Catch::Matchers::Equals(std::string{R"({
    "name": "circle 2",
    "properties": {
        "radius": 7
    },
    "shape": "Circle"
})"}));
    }

    SECTION("can print rectangles")
    {
        const Rectangle rect1{"rectangle 1", 3, 5, JSONRectanglePrintStrategy(false)};
        const Rectangle rect2{"rectangle 2", 6, 2, JSONRectanglePrintStrategy(true, 4)};

        CHECK_THAT(rect1.print(), Catch::Matchers::Equals(R"({"name":"rectangle 1","properties":{"height":5,"width":3},"shape":"Rectangle"})"));
        CHECK_THAT(rect2.print(), Catch::Matchers::Equals(std::string{R"({
    "name": "rectangle 2",
    "properties": {
        "height": 2,
        "width": 6
    },
    "shape": "Rectangle"
})"}));
    }
}

std::string print_circle_with_free_function(const Circle& circle)
{
    return fmt::format("print \"{}\" with free function", circle.name());
}

TEST_CASE("Free functions and lambdas")
{
    SECTION("can use free functions")
    {
        const Circle circle{"circle", 3, print_circle_with_free_function};

        CHECK_THAT(circle.print(), Catch::Matchers::Equals(R"(print "circle" with free function)"));
    }

    SECTION("can use lambdas")
    {
        const Circle circle{"circle", 3, [](const Circle& circle) { return fmt::format("print \"{}\" with lambda", circle.name()); }};

        CHECK_THAT(circle.print(), Catch::Matchers::Equals(R"(print "circle" with lambda)"));
    }
}
