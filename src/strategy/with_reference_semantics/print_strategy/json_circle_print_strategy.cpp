#include "json_circle_print_strategy.hpp"

#include "nlohmann/json.hpp"

std::string JSONCirclePrintStrategy::print(const Circle& circle)
{
    nlohmann::json json;

    json["shape"] = "circle";
    json["properties"]["radius"] = circle.radius();

    return json.dump();
}
