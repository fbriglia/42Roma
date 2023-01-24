char *strdup(const char *s)
{
    char    *s2;
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    s2 = malloc(len);
    while (s[i])
    {
        s2[i] = s[i];
        i++;
    }
    return(s2);
}