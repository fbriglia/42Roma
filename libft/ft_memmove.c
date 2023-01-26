/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:05:12 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 17:06:48 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    char    *d;
    char    *s;
    
    d = (char *)dst;
    s = (char *)src;
    i = 0;
    if (!(src))
        return ((void *)0);
    if (!(dst))
        return ((void *)0);
    while (i < len)
    {
        d[i] = s[i];
        i++;
    }
    return ((void *)d);
}