#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

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
        const Circle circle1{std::make_unique<SimpleCirclePrintStrategy>(), 3};
        const Circle circle2{std::make_unique<SimpleCirclePrintStrategy>(), 7};

        CHECK_THAT(circle1.print(), Catch::Matchers::Equals("Circle: radius=3"));
        CHECK_THAT(circle2.print(), Catch::Matchers::Equals("Circle: radius=7"));
    }

    SECTION("can print rectangles")
    {
        const Rectangle rect1{std::make_unique<SimpleRectanglePrintStrategy>(), 3, 5};
        const Rectangle rect2{std::make_unique<SimpleRectanglePrintStrategy>(), 6, 2};

        CHECK_THAT(rect1.print(), Catch::Matchers::Equals("Rectangle: width=3, height=5"));
        CHECK_THAT(rect2.print(), Catch::Matchers::Equals("Rectangle: width=6, height=2"));
    }
}

TEST_CASE("JSON")
{
    SECTION("can print circles")
    {
        const Circle circle1{std::make_unique<JSONCirclePrintStrategy>(), 3};
        const Circle circle2{std::make_unique<JSONCirclePrintStrategy>(), 7};

        CHECK_THAT(circle1.print(), Catch::Matchers::Equals(R"({"properties":{"radius":3},"shape":"circle"})"));
        CHECK_THAT(circle2.print(), Catch::Matchers::Equals(R"({"properties":{"radius":7},"shape":"circle"})"));
    }

    SECTION("can print rectangles")
    {
        const Rectangle rect1{std::make_unique<JSONRectanglePrintStrategy>(), 3, 5};
        const Rectangle rect2{std::make_unique<JSONRectanglePrintStrategy>(), 6, 2};

        CHECK_THAT(rect1.print(), Catch::Matchers::Equals(R"({"properties":{"height":5,"width":3},"shape":"rectangle"})"));
        CHECK_THAT(rect2.print(), Catch::Matchers::Equals(R"({"properties":{"height":2,"width":6},"shape":"rectangle"})"));
    }
}
