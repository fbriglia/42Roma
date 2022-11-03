/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:13:55 by fbriglia          #+#    #+#             */
/*   Updated: 2022/11/01 19:57:50 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof (int) * (max - min));
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
/*
int main ()
{
	int i = 0;
	int *range;
	printf("%d", ft_ultimate_range(&range, 3, 33));
	while(i++ < 30)
		printf("%d",(*range)[i]);
}
*/