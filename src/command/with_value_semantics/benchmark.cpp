#include <cassert>

#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

#include "calculator/calculator.hpp"
#include "command/add.hpp"
#include "command/multiply.hpp"

void benchmark01()
{
    ankerl::nanobench::Bench().epochs(1000).run("benchmark", [&] {
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

        ankerl::nanobench::doNotOptimizeAway(calculator);
        assert(calculator.value() == 80);
    });
}

int main()
{
    benchmark01();
}
