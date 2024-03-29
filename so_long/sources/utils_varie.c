/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_varie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:10:54 by federico          #+#    #+#             */
/*   Updated: 2023/09/14 16:42:27 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid(t_game *game, int col, int line)
{
	if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (1);
	else if (game->map.map[col][line] == 'E')
		return (-1);
	else if (game->map.map[col][line] == '0')
		return (1);
	else if (game->map.map[col][line] == 'P')
		return (1);
	return (-1);
}

int	ft_m_straight(t_game *game, int col, int line)
{
	if (valid(game, --col, line) == 1 && game->prev_move == 'N')
	{
		switch_position(game, col, line);
		return (1);
	}
	col++;
	if (valid(game, col, --line) == 1 && game->prev_move == 'W')
	{
		switch_position(game, col, line);
		return (1);
	}
	line++;
	if (valid(game, ++col, line) == 1 && game->prev_move == 'S')
	{
		switch_position(game, col, line);
		return (1);
	}
	col--;
	if (valid(game, col, ++line) == 1 && game->prev_move == 'E')
	{
		switch_position(game, col, line);
		return (1);
	}
	line--;
	return (0);
}

void	check_for_intruder(t_game *game)
{
	int x;
	int y;
	
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
				&& game->map.map[y][x] != 'P' && game->map.map[y][x] != 'E'
				&& game->map.map[y][x] != 'C' && game->map.map[y][x] != 'U'
				&& game->map.map[y][x] != 'X' && game->map.map[y][x] != 'A')
			{
				ft_printf("invalid map pop");
				ft_exit(game);		
			}
			if (game->map.map[y][x] == 'X')
				game->enemy = 1;
			if (game->map.map[y][x] == 'U')
				game->ascia = 1;
			if (game->map.map[y][x] == 'A')
				game->arbusto = 1;
		}
	}
}

void	create_map(t_game *game, char *file)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = -1;
	fd = open(file, O_RDONLY, 0);
	if (!fd)
	{
		close(fd);
		exit(0);
	}
	game->map.map = malloc(game->map.rows * sizeof(char *));
	if (!game->map.map)
		exit(0);
	line = get_next_line(fd);
	while (++i <= game->map.rows && line)
	{
		game->map.map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map.cols = ft_strlen(game->map.map[0]);
	ft_check(game);
	find_player_exit(game);
}
