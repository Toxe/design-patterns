#include "json_rectangle_print_strategy.hpp"

#include "nlohmann/json.hpp"

std::string JSONRectanglePrintStrategy::operator()(const Rectangle& rectangle) const
{
    nlohmann::json json;

    json["shape"] = "Rectangle";
    json["name"] = rectangle.name();
    json["properties"]["width"] = rectangle.width();
    json["properties"]["height"] = rectangle.height();

    return pretty_print_ ? json.dump(indent_width_) : json.dump();
}
