#pragma once

#include "abstract_products/abstract_product_a.h"

class ProductA2: public AbstractProductA {
public:
    [[nodiscard]] const char* name() override { return "ProductA2"; };
};
