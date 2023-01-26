/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:33:10 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:33:10 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int num_word(char const *s, char c)
{
    int p;
    int i;

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
char    **ft_writing(char **matrix, const char *s,char c)
{
    int i;
    int p;
    int k;
    int start;

    k = 0;
    p = 0;
    i = 0;
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
    return(matrix);
}
char    **ft_split(char const *s, char c)
{
    char    **matrix;

    matrix = malloc((num_word(s, c) + 1) * sizeof(char *));
    if (!matrix)
        return(0);
    matrix[num_word(s, c)] = NULL;
    
    return(matrix = ft_writing(matrix, s, c));
    // while (s[i])
    // {
    //     if (s[i] != c)
    //     {
    //         start = i;
    //         p = len_word(s, c, start);
    //         matrix[k] = ft_substr(s, start, p);
    //         k++;
    //         i += p;
    //     }
    //     i++;
    // }
    return (matrix);
}