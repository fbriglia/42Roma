/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:42:13 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/12 17:48:01 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_straight(t_game *game)
{
	int	col;
	int	line;

	col = game->x_enemy;
	line = game->y_enemy;
	return (ft_m_straight(game, col, line));
}

int	ft_vertical(t_game *game)
{
	int	vertical;
	int	col;
	int	line;

	col = game->x_enemy;
	line = game->y_enemy;
	vertical = game->x_enemy - game->x_player;
	col--;
	if (vertical >= 0 && valid(game, col, line) == 1 && game->prev_move != 'S')
	{
		ft_moven(game, col, line);
		return (1);
	}
	col++;
	col++;
	if (vertical < 0 && valid(game, col, line) == 1 && game->prev_move != 'N')
	{
		ft_moves(game, col, line);
		return (1);
	}
	return (0);
}

int	ft_horizontal(t_game *game)
{
	int	horizontal;
	int	col;
	int	line;

	col = game->x_enemy;
	line = game->y_enemy;
	horizontal = game->y_enemy - game->y_player;
	line--;
	if (horizontal >= 0 && valid(game, col, line) == 1
		&& game->prev_move != 'E')
	{
		ft_movew(game, col, line);
		return (1);
	}
	line++;
	line++;
	if (horizontal < 0 && valid(game, col, line) == 1 && game->prev_move != 'W')
	{
		ft_movee(game, col, line);
		return (1);
	}
	return (0);
}

int	ft_chase(t_game *game)
{
	int	vertical;
	int	horizontal;

	vertical = game->x_enemy - game->x_player;
	horizontal = game->y_enemy - game->y_player;
	if (vertical <= 0)
		vertical *= -1;
	if (horizontal <= 0)
		horizontal *= -1;
	if (vertical >= horizontal)
	{
		if (ft_vertical(game) == 1)
			return (1);
		if (ft_horizontal(game) == 1)
			return (1);
	}
	if (horizontal > vertical)
	{
		if (ft_horizontal(game) == 1)
			return (1);
		if (ft_vertical(game) == 1)
			return (1);
	}
	return (0);
}

int	move_enemy(t_game *game)
{
	int	straight;
	int	col;
	int	line;
	int	chase;

	col = game->x_enemy;
	line = game->y_enemy;
	chase = ft_chase(game);
	if (chase == 1)
		return (0);
	straight = move_straight(game);
	if (straight == 1)
		return (0);
	if (valid(game, --col, line) == 1 && game->prev_move != 'S')
		return (ft_moven(game, col, line));
	col++;
	if (valid(game, col, --line) == 1 && game->prev_move != 'E')
		return (ft_movew(game, col, line));
	line++;
	if (valid(game, ++col, line) == 1 && game->prev_move != 'N')
		return (ft_moves(game, col, line));
	col--;
	if (valid(game, col, ++line) == 1 && game->prev_move != 'W')
		return (ft_movee(game, col, line));
	line--;
	game->prev_move = '0';
	return (0);
}
