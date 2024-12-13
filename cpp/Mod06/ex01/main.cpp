#include "Serializer.hpp"

int main()
{
    Data D;
    uintptr_t raw = Serializer::serialize(&D);

    std::cout << raw << std::endl;
    std::cout << &D << std::endl;
    std::cout << Serializer::deserialize(raw) << std::endl;
}