#include "context/context.h"

int main()
{
    Context context;

    context.request1();
    context.request1();
    context.request2();
    context.request2();
    context.request3();
}
