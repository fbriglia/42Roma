/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:38:29 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/18 13:19:00 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print(int x, int y)
{
	char	i;

	i = x / 10 + '0';
	write(1, &i, 1);
	i = x % 10 + '0';
	write(1, &i, 1);
	write(1, " ", 1);
	i = y / 10 + '0';
	write(1, &i, 1);
	i = y % 10 + '0';
	write(1, &i, 1);
	if (!(x == 98))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print(a, b);
			b++;
		}
		a++;
	}
}

//int main (void)
//{
//	ft_print_comb2();
//}
