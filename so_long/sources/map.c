/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:20:32 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/12 18:00:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		i++;
	}
	if (ft_strcmp(&str[i], ".ber") != 0)
	{
		ft_printf(" %s", "\n **INVALID INPUT FILE NAME** \n\n");
		exit(0);
	}
}

void	check_map_pop(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		game->x_player = y;
		game->y_player = x;
	}
	if (game->map.map[y][x] == 'X')
	{
		game->x_enemy = y;
		game->y_enemy = x;
	}
	if ((game->map.map[y][x] != 'P') && (game->map.map[y][x] != 'E')
		&& (game->map.map[y][x] != 'C') && (game->map.map[y][x] != '0')
		&& (game->map.map[y][x] != '1') && (game->map.map[y][x] != 'X')
		&& (game->map.map[y][x] != 'A') && (game->map.map[y][x] != 'U'))
	{
		ft_printf(" %s", "\n **INVALID MAP POPULATION** \n\n");
		ft_exit(game);
	}
	x++;
}

void	find_player_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			check_map_pop(game, x, y);
			x++;
		}
		y++;
	}
}

int	ft_count_rows(int fd)
{
	int		i;
	char	buff;

	i = 1;
	buff = 0;
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
			i++;
	}
	return (i);
}

void	ft_parse_map(t_game *game, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY, 0);
	if (!fd)
	{
		close(fd);
		exit(0);
	}
	game->map.rows = ft_count_rows(fd);
	close(fd);
	create_map(game, file);
	game->was_collectible = 0;
	close(fd);
}
