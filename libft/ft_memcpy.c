/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:00:20 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/24 21:10:35 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *dest, void *src, size_t len)
{
    int i;

    i = 0;
    if(src[i] == '\0')
        return (0);
    while(src[i])
        i++;
    if(i < len)
    {
        i = 0;
        while(src[i])
        {
            dest[i] = src[i];
            i++;
        }
        return(dest);
    }
    while(i < len)
    {
        dest[i] = src[i];
        i++;
    }
    return(dest);
}