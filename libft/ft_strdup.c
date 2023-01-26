/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:33:28 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:33:28 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *s2;
    int     len;
    int     i;

    if (!(s))
        return(NULL);
    i = 0;
    len = ft_strlen((char *)s);
    s2 = malloc((len + 1) * sizeof(char));
    if(!s2)
        return (NULL);
    while (s[i] != 0)
    {
        s2[i] = s[i];
        i++;
    }
    s2[i] = '\0';
    return(s2);
}