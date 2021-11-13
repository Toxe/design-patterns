#include "adapter.h"

#include "adaptee/adaptee.h"

std::string Adapter::request()
{
    return adaptee_.specific_request();
}
