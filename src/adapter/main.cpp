#include "adaptee/adaptee.h"
#include "adapter/adapter.h"
#include "client/client.h"

int main()
{
    Adaptee adaptee;
    Adapter adapter(adaptee);

    client(adapter);
}
