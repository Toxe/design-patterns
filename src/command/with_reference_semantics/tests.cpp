#include "catch2/catch_test_macros.hpp"

#include "calculator/calculator.hpp"
#include "command/add.hpp"
#include "command/multiply.hpp"

TEST_CASE("Commands")
{
    SECTION("Add")
    {
        const Add add{5};

        CHECK(add.execute(0) == 5);
        CHECK(add.execute(3) == 8);

        CHECK(add.undo(5) == 0);
        CHECK(add.undo(8) == 3);
    }

    SECTION("Multiply")
    {
        const Multiply mul{5};

        CHECK(mul.execute(0) == 0);
        CHECK(mul.execute(1) == 5);
        CHECK(mul.execute(3) == 15);

        CHECK(mul.undo(0) == 0);
        CHECK(mul.undo(5) == 1);
        CHECK(mul.undo(15) == 3);
    }
}

TEST_CASE("Calculator")
{
    Calculator calculator;

    SECTION("Initial value is zero")
    {
        CHECK(calculator.value() == 0);
    }

    SECTION("Compute, Undo and Redo")
    {
        // compute
        calculator.compute(std::make_unique<Add>(3));
        CHECK(calculator.value() == 3);

        calculator.compute(std::make_unique<Add>(2));
        CHECK(calculator.value() == 5);

        calculator.compute(std::make_unique<Multiply>(2));
        CHECK(calculator.value() == 10);

        calculator.compute(std::make_unique<Add>(10));
        CHECK(calculator.value() == 20);

        calculator.compute(std::make_unique<Multiply>(3));
        CHECK(calculator.value() == 60);

        // undo
        calculator.undo();
        CHECK(calculator.value() == 20);

        calculator.undo();
        CHECK(calculator.value() == 10);

        calculator.undo();
        CHECK(calculator.value() == 5);

        calculator.undo();
        CHECK(calculator.value() == 3);

        calculator.undo();
        CHECK(calculator.value() == 0);

        // redo
        calculator.redo();
        CHECK(calculator.value() == 3);

        calculator.redo();
        CHECK(calculator.value() == 5);

        calculator.redo();
        CHECK(calculator.value() == 10);

        calculator.redo();
        CHECK(calculator.value() == 20);

        calculator.redo();
        CHECK(calculator.value() == 60);
    }

    SECTION("empty undo and redo stacks")
    {
        calculator.compute(std::make_unique<Add>(1));
        calculator.compute(std::make_unique<Add>(2));
        calculator.compute(std::make_unique<Add>(3));
        CHECK(calculator.value() == 6);

        // undo
        calculator.undo();
        calculator.undo();
        calculator.undo();
        CHECK(calculator.value() == 0);

        // empty undo stack
        calculator.undo();
        CHECK(calculator.value() == 0);

        calculator.undo();
        CHECK(calculator.value() == 0);

        // redo
        calculator.redo();
        calculator.redo();
        calculator.redo();
        CHECK(calculator.value() == 6);

        // empty redo stack
        calculator.redo();
        CHECK(calculator.value() == 6);

        calculator.redo();
        CHECK(calculator.value() == 6);
    }

    SECTION("clear redo stack after executing new commands")
    {
        calculator.compute(std::make_unique<Add>(1));
        calculator.compute(std::make_unique<Add>(2));
        calculator.compute(std::make_unique<Add>(3));
        CHECK(calculator.value() == 6);

        calculator.undo();
        calculator.undo();
        CHECK(calculator.value() == 1);

        calculator.compute(std::make_unique<Add>(10));
        CHECK(calculator.value() == 11);

        // empty redo stack
        calculator.redo();
        CHECK(calculator.value() == 11);
    }
}
