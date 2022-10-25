/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:40:37 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/18 12:30:54 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_fun(int x, int y, int z)
{
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (!(x == '7'))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_fun(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

//int main(void)
//{
//	ft_print_comb();
//}
