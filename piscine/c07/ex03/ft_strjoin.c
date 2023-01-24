/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:54:22 by fbriglia          #+#    #+#             */
/*   Updated: 2022/11/01 18:51:53 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
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
	char	*str;

	if (size < 1)
	{
		str = malloc(sizeof (char) * 1);
		return (str);
	}
	j = 0;
	i = -1;
	while (++i <= size)
		j = j + ft_strlen(strs[i]);
	j = j + (ft_strlen(sep) * size);
	str = (char *)malloc(sizeof(char) * j + 1);
	i = -1;
	str[0] = 0;
	while (strs[++i])
	{
		str = ft_strcat(str, strs[i]);
		if (i < size)
			str = ft_strcat(str, sep);
	}
	str[j + 1] = 0;
	return (str);
}
/*
int	main(int argc, char **argv)
{
	char	*sep = "  ";
	printf("%s",ft_strjoin(2  , argv, " "));
}
*/