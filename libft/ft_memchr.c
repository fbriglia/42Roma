void *memchr(const void *s, int c, size_t n)
{
    size_t i;
    char    *str2;

    i = 0;
    while(str[i] && i <= n)
    {
        if(str[i] == c)
        {
            str2 = &str[i];
            return(str2);
        }
        i++;
    }
    return((void *)str2);
}