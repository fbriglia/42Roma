/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:34:03 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/26 14:34:03 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s)
		return (0);
	if ((len == 0 && start == 0) || (size_t)start >= ft_strlen(s))
	{
		s2 = (char *) malloc(sizeof(char) * 1);
		s2[0] = 0;
		return (s2);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < len && s[start + i] != '\0' && start <= ft_strlen((char *)s))
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
