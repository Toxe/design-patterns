#pragma once

#include "../shape/circle.hpp"
#include "print_strategy.hpp"

class SimpleCirclePrintStrategy : public PrintStrategy<Circle> {
public:
    std::string print(const Circle& circle) override;
};
