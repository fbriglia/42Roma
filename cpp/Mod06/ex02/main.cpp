#include "Base.hpp"

int main ()
{
    Base C;
    A A;
    Base *F = C.generate();
    C.identify(F);
    C.identify(A);
}