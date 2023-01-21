#include <cassert>
#include <memory>

#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

#include "calculator/calculator.hpp"
#include "command/add.hpp"
#include "command/multiply.hpp"

void benchmark01()
{
    ankerl::nanobench::Bench().epochs(1000).run("benchmark", [&] {
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

        calculator.compute(std::make_unique<Add>(10));
        calculator.compute(std::make_unique<Multiply>(2));
        calculator.compute(std::make_unique<Add>(10));

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
