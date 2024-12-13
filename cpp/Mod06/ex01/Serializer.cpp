#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& S)
{
    *this = S;
}

Serializer& Serializer::operator=(const Serializer& S)
{
    (void)S;
    return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return (uintptr_t)(void*)ptr;
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return (Data*)raw;
}