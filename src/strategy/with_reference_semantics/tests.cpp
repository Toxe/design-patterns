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
        const Circle circle1{"circle 1", 3, std::make_unique<SimpleCirclePrintStrategy>(true)};
        const Circle circle2{"circle 2", 7, std::make_unique<SimpleCirclePrintStrategy>(false)};

        CHECK_THAT(circle1.print(), Catch::Matchers::Equals("[Circle] circle 1: radius=3"));
        CHECK_THAT(circle2.print(), Catch::Matchers::Equals("[Circle] circle 2"));
    }

    SECTION("can print rectangles")
    {
        const Rectangle rect1{"rectangle 1", 3, 5, std::make_unique<SimpleRectanglePrintStrategy>(true)};
        const Rectangle rect2{"rectangle 2", 6, 2, std::make_unique<SimpleRectanglePrintStrategy>(false)};

        CHECK_THAT(rect1.print(), Catch::Matchers::Equals("[Rectangle] rectangle 1: width=3, height=5"));
        CHECK_THAT(rect2.print(), Catch::Matchers::Equals("[Rectangle] rectangle 2"));
    }
}

TEST_CASE("JSON")
{
    SECTION("can print circles")
    {
        const Circle circle1{"circle 1", 3, std::make_unique<JSONCirclePrintStrategy>(false)};
        const Circle circle2{"circle 2", 7, std::make_unique<JSONCirclePrintStrategy>(true, 4)};

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
        const Rectangle rect1{"rectangle 1", 3, 5, std::make_unique<JSONRectanglePrintStrategy>(false)};
        const Rectangle rect2{"rectangle 2", 6, 2, std::make_unique<JSONRectanglePrintStrategy>(true, 4)};

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
