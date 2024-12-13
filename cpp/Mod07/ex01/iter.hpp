#ifndef ITER_HPP
#define ITER_HPP

#include "../ex00/Whatever.hpp"



template <typename T> void iter(T* c , int i , int (*func)(int,int))
{
    for (int j = 0; j < i; j++)
        func(c[j],c[j+1]);
}

#endif