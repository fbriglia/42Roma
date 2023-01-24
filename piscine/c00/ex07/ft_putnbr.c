/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:13:44 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/19 17:46:31 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putnbr(int nbr)
{
	long	nbrlong;
	char	c;

	nbrlong = nbr;
	if (nbrlong < 0)
	{
		write(1, "-", 1);
		nbrlong = -nbrlong;
	}
	if (nbrlong <= 9)
	{
		c = nbrlong + '0';
	}
	else
	{
		c = nbrlong % 10 + '0';
		ft_putnbr(nbrlong / 10);
	}
	write(1, &c, 1);
}
//int main()
//{
//  ft_put_nbr(-2147483648);
//  return 0;
//}
