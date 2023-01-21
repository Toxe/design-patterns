#include "fmt/core.h"

#include "calculator/calculator.hpp"
#include "command/add.hpp"
#include "command/multiply.hpp"

int main()
{
    Calculator calculator;

    calculator.compute(Add(3));
    calculator.compute(Multiply(2));
    calculator.compute(Multiply(5));
    calculator.compute(Multiply(100));

    calculator.undo();
    calculator.undo();
    calculator.undo();

    calculator.redo();
    calculator.redo();

    calculator.compute(Add(10));
    calculator.compute(Multiply(2));
    calculator.compute(Add(10));

    calculator.undo();
    calculator.undo();

    calculator.redo();

    fmt::print("calculator value: {}\n", calculator.value());
}
