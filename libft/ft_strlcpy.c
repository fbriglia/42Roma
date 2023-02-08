/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/01/26 14:33:37 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:33:37 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	k;

	k = (size_t)ft_strlen(src);
	i = 0;
	if (!(src))
		return (0);
	if (len > 0)
	{
		while (src[i] && i < len -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((int)ft_strlen(src));
}
