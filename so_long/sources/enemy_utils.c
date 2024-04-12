/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:07:34 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/15 17:54:41 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position(t_game *game, int col, int line)
{
	int	tcol;
	int	tline;

	tcol = game->x_enemy;
	tline = game->y_enemy;
	game->x_enemy = col;
	game->y_enemy = line;
	if (game->map.map[col][line] == 'P')
	{
		ft_printf("\n\nYOU LOSE👻\n\n");
		ft_exit(game);
		exit(0);
	}
	if (game->was_collectible == 1)
		game->map.map[tcol][tline] = 'C';
	else
		game->map.map[tcol][tline] = '0';
	if (game->map.map[col][line] == 'C')
		game->was_collectible = 1;
	else
		game->was_collectible = 0;
	game->map.map[col][line] = 'X';
}

int	ft_moven(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'N';
	return (0);
}

int	ft_movew(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'W';
	return (0);
}

int	ft_movee(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'E';
	return (0);
}

int	ft_moves(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'S';
	return (0);
}
