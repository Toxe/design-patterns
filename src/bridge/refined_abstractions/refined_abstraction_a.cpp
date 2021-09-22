#include "refined_abstraction_a.h"

#include <fmt/core.h>

void RefinedAbstractionA::print_values()
{
    for (const auto i : values()) {
        imp().print_value(i);
        imp().print_delimiter();
    }

    fmt::print("\n");
}
