#include <fmt/core.h>

#include "adaptee/adaptee.h"
#include "adapter/adapter.h"
#include "client/client.h"

int main()
{
    Adaptee adaptee;
    Adapter adapter(adaptee);

    const auto value = client(adapter);

    fmt::print("{}\n", value);
}
