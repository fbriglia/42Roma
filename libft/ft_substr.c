char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    char    *s2;
    
    if (!s)
        return (0);
    i = 0;
    s2 = malloc(len + 1 * sizeof(char));
    if (start > ft_strlen(s))
        return (0);
    while(i <= len)
    {
        s2[i] = s[start + i];
        i++; 
    }
    s2[i] = 0;
    return (s2);
}