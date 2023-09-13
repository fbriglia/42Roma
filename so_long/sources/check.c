/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:26:05 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/24 17:13:44 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_shape(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.map[i]) != game->map.cols)
		{
			ft_printf(" %s", "\n **INVALID MAP SHAPE** \n\n");
			exit(0);
		}
		i++;
	}
}

void	check_top_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y++ <= game->map.rows)
	{
		x = 0;
		if (y == 0)
		{
			while (game->map.map[y][x++])
			{
				if (game->map.map[y][x] != '1')
					exit(0);
			}
		}
		if (y == game->map.rows - 1)
		{
			while (game->map.map[game->map.rows - 1][x])
			{
				if (game->map.map[y][x] != '1')
					exit(0);
				x++;
			}
		}
	}
}

void	check_side_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		if (game->map.map[y][x] == 1)
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			exit(0);
		}
		y++;
	}
	y = 0;
	while (y < game->map.rows)
	{
		x = game->map.cols - 1;
		if (game->map.map[y][x] != '1')
			exit(0);
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < game->map.rows)
	{
		x = 0;
		while (game->map.map[i][x++])
		{
			if (game->map.map[i][x] == 'C')
				c++;
		}
		i++;
	}
	if (c < 1)
	{
		ft_printf(" %s", "\n **INVALID MAP POPULATION** \n\n");
		exit(0);
	}
	game->collectibles = c;
}

void	ft_check(t_game *game)
{
	int	i;

	check_shape(game);
	check_top_border(game);
	check_side_border(game);
	i = ft_check_map_pop(game);
	if (i == 1)
	{
		ft_printf("\n **INVALID MAP POPULATION** \n\n");
		exit (0);
	}
	count_collectibles(game);
}
