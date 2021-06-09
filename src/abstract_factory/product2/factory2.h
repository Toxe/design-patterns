#pragma once

#include "abstract_products/abstract_factory.h"
#include "product_a2.h"
#include "product_b2.h"

class ConcreteFactory2: public AbstractFactory {
public:
    [[nodiscard]] ProductA2* create_product_a() override { return new ProductA2; };
    [[nodiscard]] ProductB2* create_product_b() override { return new ProductB2; };
};
