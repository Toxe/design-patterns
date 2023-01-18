#include "json_circle_print_strategy.hpp"

#include "nlohmann/json.hpp"

std::string JSONCirclePrintStrategy::print(const Circle& circle) const
{
    nlohmann::json json;

    json["shape"] = "Circle";
    json["name"] = circle.name();
    json["properties"]["radius"] = circle.radius();

    return pretty_print_ ? json.dump(indent_width_) : json.dump();
}
