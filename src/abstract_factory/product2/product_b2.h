#pragma once

#include "abstract_products/abstract_product_b.h"

class ProductB2: public AbstractProductB {
public:
    [[nodiscard]] const char* name() override { return "ProductB2"; };
};
