/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:32:42 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:32:42 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, void *src, size_t len)
{
    size_t i;
    char    *d;
    char    *s;
    
    if(!(src))
        return (0);

    d = (char *)dest;
    s = (char *)src;
    i = 0;    
    while(i < len)
    {
        d[i] = s[i];
        i++;
    }
    return((void *)d);
}