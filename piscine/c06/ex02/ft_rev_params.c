/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:26:48 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/31 19:27:02 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	x;

	x = argc;
	while (x-- > 1)
	{
		i = 0;
		while (argv[x][i] != 0)
		{
			write(1, &argv[x][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}