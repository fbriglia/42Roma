#include "iter.hpp"

int min(int a, int b)
{
    if (a < b)
    {
        std::cout << a << std::endl;
        return a;
    }
    std::cout << b << std::endl;
    return b;
}

int main ()
{
    char array[5] = {4, 5, 7, 1, 9};
    
    iter(array, 4, &min);
}