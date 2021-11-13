#include "refined_abstraction_a.h"

#include <sstream>

std::string RefinedAbstractionA::print_values()
{
    std::stringstream sstream;

    for (const auto i : values()) {
        sstream << imp().print_value(i);
        sstream << imp().print_delimiter();
    }

    return sstream.str();
}
