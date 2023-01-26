/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:32:31 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:32:31 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    char    *s2;

    s2 = (char  *)s;
    i = 0;
    while(s2[i] && i <= n)
    {
        if(s2[i] == c)
        {
            return (&s2[i]);
        }
        i++;
    }
    return (s2);
}
