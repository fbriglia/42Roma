/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:05:16 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/26 12:06:20 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	x;
	int	result;

	result = nb;
	x = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	while (x < power)
	{
		result = result * nb;
		x++;
	}
	return (result);
}
/*
int main ()
{
	printf("%d",ft_iterative_power(12, 999999999));
}
*/
