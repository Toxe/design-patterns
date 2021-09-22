#include "client/client.h"
#include "concrete_implementors/concrete_implementor1.h"
#include "concrete_implementors/concrete_implementor2.h"
#include "refined_abstractions/refined_abstraction_a.h"
#include "refined_abstractions/refined_abstraction_b.h"

int main()
{
    ConcreteImplementor1 concrete_implementor1;
    ConcreteImplementor2 concrete_implementor2;

    RefinedAbstractionA refined_abstraction_a1{{1, 2, 3, 4, 5}, concrete_implementor1};
    RefinedAbstractionA refined_abstraction_a2{{1, 2, 3, 4, 5}, concrete_implementor2};
    RefinedAbstractionB refined_abstraction_b1{{1, 2, 3, 4, 5}, concrete_implementor1};
    RefinedAbstractionB refined_abstraction_b2{{1, 2, 3, 4, 5}, concrete_implementor2};

    client(refined_abstraction_a1);
    client(refined_abstraction_a2);
    client(refined_abstraction_b1);
    client(refined_abstraction_b2);
}
