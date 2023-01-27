/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:33:18 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:33:18 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int			i;
	const char	*str2;

	str2 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str2 = &str[i];
			return ((char *)str2);
		}
		i++;
	}
	if (c == '\0')
	{
		str2 = &str[i];
		return ((char *)str2);
	}
	return ((char *)str2);
}
