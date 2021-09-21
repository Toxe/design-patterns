#include "adapter.h"

#include "adaptee/adaptee.h"

void Adapter::request()
{
    adaptee_.specific_request();
}
