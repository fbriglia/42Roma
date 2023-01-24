char *ft_strchr(const char *str, int c)
{
    int i;
    char    *str2;

    i = 0;
    while(str[i])
    {
        if(str[i] == c)
        {
            str2 = &str[i];
            return(str2);
        }
        i++;
    }
    return(str2);
}