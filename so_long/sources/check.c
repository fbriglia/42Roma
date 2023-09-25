/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:26:05 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/14 16:55:00 by federico         ###   ########.fr       */
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
			ft_exit(game);
		}
		i++;
	}
}

void	check_top_border(t_game *game)
{
	int	x;

	x = -1;
	while (game->map.map[0][++x])
	{
		if (game->map.map[0][x] != '1')
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			ft_exit(game);
		}
	}
	x = -1;
	while (++x < game->map.cols - 1)
	{
		if (game->map.map[game->map.rows - 1][x] != '1')
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			ft_exit(game);
		}
	}
}

void	check_side_border(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.rows - 1)
	{
		if (game->map.map[y][0] != '1')
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			ft_exit(game);
		}
		y++;
	}
	y = 0;
	while (y < game->map.rows)
	{
		if (game->map.map[y][game->map.cols -1] != '1')
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			ft_exit(game);
		}
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
		ft_exit(game);
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
		ft_exit(game);
	}
	check_for_intruder(game);
	count_collectibles(game);
}
