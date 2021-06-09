#include <memory>

#include <fmt/core.h>

#include "abstract_products/abstract_factory.h"
#include "abstract_products/abstract_product_a.h"
#include "abstract_products/abstract_product_b.h"

void client(AbstractFactory* factory)
{
    std::unique_ptr<AbstractProductA> product_a(factory->create_product_a());
    std::unique_ptr<AbstractProductB> product_b(factory->create_product_b());

    fmt::print("Product A: {}\n", product_a->name());
    fmt::print("Product B: {}\n", product_b->name());
}
