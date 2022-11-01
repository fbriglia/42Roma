/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:54:22 by fbriglia          #+#    #+#             */
/*   Updated: 2022/11/01 01:13:39 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	return (dest);
}	

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	i = 0;
	while (strs[i])
	{
		j = ft_strlen(strs[i]);
		c = c + j;
		i++;
	}
	j = ft_strlen(sep);
	str = (char *)malloc(sizeof(char) * (c + j * size - 1));
	i = 0;
	while (strs[i])
	{
		str = ft_strcat(str, strs[i]);
		if (i < size)
			str = ft_strcat(str, sep);
		i++;
	}
	return (strs);
}
