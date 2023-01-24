int ft_strlcpy(char *dest, char *src, size_t len)
{
    int i;

    i = 0;
    if(src[i] == '\0')
        return(0);
    while (src[i] < len)
    {
        dest[i] = src [i];
        i++;
    }
    return(i);
}