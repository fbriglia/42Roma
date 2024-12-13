#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "iostream"

class Data {

};
    class Serializer 
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
};


#endif