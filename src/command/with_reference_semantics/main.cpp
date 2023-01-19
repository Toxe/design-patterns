#include <memory>
#include <utility>

#include "fmt/core.h"

#include "calculator/calculator.hpp"
#include "command/add.hpp"
#include "command/multiply.hpp"

int main()
{
    Calculator calculator;

    calculator.compute(std::make_unique<Add>(3));
    calculator.compute(std::make_unique<Multiply>(2));
    calculator.compute(std::make_unique<Multiply>(5));
    calculator.compute(std::make_unique<Multiply>(100));

    calculator.undo();
    calculator.undo();
    calculator.undo();

    calculator.redo();
    calculator.redo();

    auto op1 = std::make_unique<Add>(10);
    auto op2 = std::make_unique<Multiply>(2);
    auto op3 = std::make_unique<Add>(10);

    calculator.compute(std::move(op1));
    calculator.compute(std::move(op2));
    calculator.compute(std::move(op3));

    calculator.undo();
    calculator.undo();

    calculator.redo();

    fmt::print("calculator value: {}\n", calculator.value());
}
