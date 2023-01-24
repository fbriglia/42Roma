/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:42:29 by fbriglia          #+#    #+#             */
/*   Updated: 2022/11/01 02:21:15 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*x;
	int	y;
	int	i;

	if (min >= max)
		return (x);
	i = 0;
	y = max - min;
	x = (int *)malloc(sizeof (int) * y);
	while (min < max)
	{
		x[i] = min;
		min++;
		i++;
	}
	return (x);
}
/*
int main ()
{
	ft_range(2,33);
}
*/
