/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:06:05 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/27 17:36:03 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb != 2 && nb % 2 == 0)
		return (0);
	if (nb != 3 && nb % 3 == 0)
		return (0);
	while (i <= nb / i +1)
	{
		if (nb % i == 0)
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
        if (nb % 2 == 0)
            nb++;
		else nb += 2;
	return (nb);
}
/*
int main()
{
	printf("%d",ft_find_next_prime(2147483630));
}
*/
