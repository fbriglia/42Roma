#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_quotes(const char *s, int *i, char quote_found, int *start)
{
    if(start && *start < 0)
        *start = *i;
    (*i)++;
    while (s[*i] != '\0')
    {
        if (s[*i] != quote_found)
        {
            (*i)++;
        }
        else
            break;
    }
}

int check_double_pipe(char const *s, char c)
{
    int i;
    int p;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\'' || s[i] == '\"')
            handle_quotes(s, &i, s[i], NULL);
        if (s[i] == c)
        {
            p = i + 1;
            while (s[p] == ' ')
                p++;
            if (s[p] == c)
                return (-1);
        }
        i++;
    }
    return(0);
}

static int strlen_neg_pos(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

static int count_nbr_words(const char *str, char c)
{
    int i;
    int j;
    int trigger;

    i = -1;
    j = 0;
    trigger = 0;
    if (check_double_pipe(str, '|'))
        return (-1);
    while (str[++i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            handle_quotes(str, &i, str[i], NULL);
        if (!str[i])
            return (j);
        if (str[i] != c && trigger == 0)
        {
            trigger = 1;
            j++;
        }
        else if (str[i] == c)
            trigger = 0;
    }
    return (j);
}

static char *copy_words(const char *str, int *start, int end)
{
    char *word;
    int i;

    i = 0;
    word = malloc((end - *start + 1) * sizeof(char));
    if (!word)
        return (0);
    while (*start < end)
    {
        word[i] = str[*start];
        i++;
        (*start)++;
    }
    word[i] = '\0';
    *start = -1;
    return (word);
}

char **prova(int start, int j, char const *s, char c)
{
    char **split;
    int i;
    int n_words;

    n_words = count_nbr_words(s, c);
    if (n_words == -1)
        return (0);
    split = malloc((n_words + 1) * sizeof(char *));
    if (!split)
        return (0);
    i = -1;
    while (++i <= strlen_neg_pos(s))
    {
        if (s[i] == '\'' || s[i] == '\"')
            handle_quotes(s, &i, s[i], &start);
        if (s[i] != c && start < 0)
            start = i;
        else if ((s[i] == c || i == strlen_neg_pos(s)) && start >= 0)
            split[j++] = copy_words(s, &start, i);
    }
    split[j] = 0;
    return (split);
}

char **ft_split(char const *s, char c)
{
    int start;
    int j;

    start = -1;
    j = 0;
    if (!s)
        return (0);
    return (prova(start, j, s, c));
}

int main(void)
{
    char *str = " ";
    char **matrix;
    int		i;

    int n = count_nbr_words(str, '|');
    if (n == -1)
    {
        printf("zsh: parse error near `|'");
        return (1);
    }
    matrix = ft_split(str, '|');
    printf("first string = %s\n", matrix[0]);
    printf("second = %s\n", matrix[1]);
    
    i = -1;
        printf("\n\nPARSED COMMANDS\n\n");
    while (++i < n)
    {
        int n2 = count_nbr_words(matrix[i], ' ');
        char **matrix2 = ft_split(matrix[i], ' ');
        int j = -1;
        while (++j < n2)
        {
            printf("%s\n", matrix2[j]);
        }
    }
}