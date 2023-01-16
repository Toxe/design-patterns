#pragma once

#include "../shape/circle.hpp"
#include "print_strategy.hpp"

class JSONCirclePrintStrategy : public PrintStrategy<Circle> {
public:
    std::string print(const Circle& circle) override;
};
