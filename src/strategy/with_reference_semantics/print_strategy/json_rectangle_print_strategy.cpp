#include "json_rectangle_print_strategy.hpp"

#include "nlohmann/json.hpp"

std::string JSONRectanglePrintStrategy::print(const Rectangle& rectangle)
{
    nlohmann::json json;

    json["shape"] = "rectangle";
    json["properties"]["width"] = rectangle.width();
    json["properties"]["height"] = rectangle.height();

    return json.dump();
}
