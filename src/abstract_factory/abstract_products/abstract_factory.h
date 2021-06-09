#pragma once

class AbstractProductA;
class AbstractProductB;

class AbstractFactory {
public:
    [[nodiscard]] virtual AbstractProductA* create_product_a() = 0;
    [[nodiscard]] virtual AbstractProductB* create_product_b() = 0;

    virtual ~AbstractFactory() = default;
};
