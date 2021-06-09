#include <memory>

#include "client/client.h"
#include "product1/factory1.h"
#include "product2/factory2.h"

int main()
{
    const auto factory1 = std::make_unique<ConcreteFactory1>();
    const auto factory2 = std::make_unique<ConcreteFactory2>();

    client(factory1.get());
    client(factory2.get());
}
