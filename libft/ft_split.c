int num_word(char const *s, char c)
{
    int p;
    int i;
    int f;

    i = 0;
    p = 0;
    if (s[i] != c)
      p = 1;
    while (s[i])
    {
        
        if (s[i] == c)
        {
            if (s[++i] != c && s[i] != '\0')
              p++; 
            else 
              i--;
        }
        i++;
    }
    return (p);
}
int len_word(char const *s, char c, int i)
{
    int j;

    j = 1;
    while (s[i] == c)
        i++;
    while (s[i + j] != c)
        j++;
    return(j);
}
char **ft_split(char const *s, char c)
{
    char    **matrix;
    int     p;
    int     k;
    int     start;
    int     i;

    k = 0;
    i = 0;
    matrix = malloc((num_word(s, c) + 1) * sizeof(char *))
    matrix[num_word(s, c)] = NULL;
    while (s[i])
    {
        if (s[i] != c)
        {
            start = i;
            p = len_word(s, c, start);
            matrix[k] = ft_substr(s, start, p);
            k++;
            i += p;
        }
        i++;
    }
    return (matrix);
}