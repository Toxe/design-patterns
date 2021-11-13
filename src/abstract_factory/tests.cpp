#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "product1/factory1.h"
#include "product2/factory2.h"

TEST_CASE("ConcreteFactory1 returns Product A1 and B1")
{
    const auto factory = std::make_unique<ConcreteFactory1>();

    std::unique_ptr<AbstractProductA> product_a(factory->create_product_a());
    std::unique_ptr<AbstractProductB> product_b(factory->create_product_b());

    REQUIRE_THAT(product_a->name(), Catch::Matchers::Equals("ProductA1"));
    REQUIRE_THAT(product_b->name(), Catch::Matchers::Equals("ProductB1"));
}

TEST_CASE("ConcreteFactory2 returns Product A2 and B2")
{
    const auto factory = std::make_unique<ConcreteFactory2>();

    std::unique_ptr<AbstractProductA> product_a(factory->create_product_a());
    std::unique_ptr<AbstractProductB> product_b(factory->create_product_b());

    REQUIRE_THAT(product_a->name(), Catch::Matchers::Equals("ProductA2"));
    REQUIRE_THAT(product_b->name(), Catch::Matchers::Equals("ProductB2"));
}
