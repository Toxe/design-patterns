#include "refined_abstraction_b.h"

#include <fmt/core.h>

void RefinedAbstractionB::print_values()
{
    int index = 1;

    for (const auto i : values()) {
        fmt::print("value #{} = ", index);

        imp().print_value(i);
        imp().print_delimiter();

        ++index;
    }

    fmt::print("\n");
}
