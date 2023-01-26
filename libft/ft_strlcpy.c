/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:33:37 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:33:37 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcpy(char *dest, char *src, size_t len)
{
    size_t i;

    i = 0;
    if(!(src))
        return(0);
    while (i < len)
    {
        dest[i] = src [i];
        i++;
    }
    return((int)i);
}