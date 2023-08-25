/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:30:29 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/24 17:07:59 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map_pop(t_game *game)
{
	int	i;
	int	x;
	int	p;
	int	e;

	i = 0;
	e = 0;
	p = 0;
	while (game->map.map[i])
	{
		x = 0;
		while (game->map.map[i][x++])
		{
			if (game->map.map[i][x] == 'P')
				p++;
			if (game->map.map[i][x] == 'E')
				e++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (1);
	else
		return (0);
}

int	get_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	nb;

	nb = (long)n;
	size = (int)get_count(nb);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb == 0)
		res[0] = 48;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[--size] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}
