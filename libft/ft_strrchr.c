/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:38:01 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/25 12:38:01 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
		{
			return ((char *)&str[len]);
		}
		if (c == 0)
			return (0);
		len--;
	}
	return (0);
}
