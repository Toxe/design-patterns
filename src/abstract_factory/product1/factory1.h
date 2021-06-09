#pragma once

#include "abstract_products/abstract_factory.h"
#include "product_a1.h"
#include "product_b1.h"

class ConcreteFactory1: public AbstractFactory {
public:
    [[nodiscard]] ProductA1* create_product_a() override { return new ProductA1; };
    [[nodiscard]] ProductB1* create_product_b() override { return new ProductB1; };
};
