#include "refined_abstraction_b.h"

#include <sstream>

std::string RefinedAbstractionB::print_values()
{
    std::stringstream sstream;
    int index = 1;

    for (const auto i : values()) {
        sstream << "value #" << index << " = ";
        sstream << imp().print_value(i);
        sstream << imp().print_delimiter();

        ++index;
    }

    return sstream.str();
}
