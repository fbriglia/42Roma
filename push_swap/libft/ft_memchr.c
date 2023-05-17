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

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s2;
	char	c2;
	size_t	i;

	s2 = (char *)s;
	c2 = c;
	i = 0;
	while (i < n)
	{
		if (*s2 == c2)
			return ((void *)s2);
		s2++;
		i++;
	}
	return (0);
}
