#include "libft.h"

void *calloc(size_t nmemb, size_t size)
{
    void    *ptr;
    int i;
    
    i = 0;
    if (nmeb == 0 || size == 0)
        return (0);
    ptr = malloc(nmeb * size);
    while (ptr[i] < nmeb * size)
    {
        ptr[i] = 0;
        i ++;
    }
}