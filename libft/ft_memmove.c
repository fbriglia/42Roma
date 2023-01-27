/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:05:12 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/27 15:57:28 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;
	char	*lastd;
	char	*lasts;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (d < s)
	{
		while (len --)
			*d++ = *s++;
	}
	else
	{
		lasts = s + len - 1;
		lastd = d + len - 1;
		while (len --)
			*lastd-- = *lasts--;
	}
	return (dst);
}
