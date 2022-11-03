/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:35:26 by fbriglia          #+#    #+#             */
/*   Updated: 2022/11/01 02:17:49 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof (char) * i + 1);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
/*
int main()
{
	char	a[]="hello";
	ft_strdup(a);
}
*/