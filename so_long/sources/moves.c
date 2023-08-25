/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:20:17 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/24 20:31:58 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_collect(t_game *game)
{
	char	*collect;
	char	*join;

	collect = ft_itoa(game->collectibles);
	join = ft_join("To collect : ", collect);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows + 1) * 32, 0x00000000, join);
	free(collect);
	free(join);
	game->collectibles--;
	collect = ft_itoa(game->collectibles);
	join = ft_join("To collect : ", collect);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows + 1) * 32, 0xCFFF04, join);
	free(collect);
	free(join);
	return (1);
}

int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	if (game->map.map[col][line] == 'X')
	{
		ft_printf("\n\nYOU LOSE👻\n\n");
		ft_exit(game);
	}
	else if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (ft_collect(game));
	else if (game->map.map[col][line] == 'E' && game->collectibles > 0)
		return (-1);
	else if (game->map.map[col][line] == 'E' && game->collectibles == 0)
	{
		ft_printf("\n\nYOU WIN🏆\n\n");
		ft_exit(game);
	}
	else if (pressed_key != KEY_W && pressed_key != KEY_S
		&& pressed_key != KEY_A && pressed_key != KEY_D
		&& pressed_key != KEY_UP && pressed_key != KEY_DOWN
		&& pressed_key != KEY_LEFT && pressed_key != KEY_RIGHT)
		return (-1);
	return (1);
}

// void	update_image(int keycode, t_game *game)
// {
// 	int	len;

// 	len = SPRITE_SIZE;
// 	if (keycode == KEY_A || keycode == KEY_LEFT)
// 		game->map.player = mlx_xpm_file_to_image(game->mlx,
// 				"./img/player_sx.xpm", &len, &len);
// 	else if (keycode == KEY_W || keycode == KEY_UP)
// 		game->map.player = mlx_xpm_file_to_image(game->mlx,
// 				"./img/player_up.xpm", &len, &len);
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 		game->map.player = mlx_xpm_file_to_image(game->mlx,
// 				"./img/player_dx.xpm", &len, &len);
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 		game->map.player = mlx_xpm_file_to_image(game->mlx,
// 				"./img/player_down.xpm", &len, &len);
// }

int	move_player(t_game *game, int col, int line, int keycode)
{
	int		valid;
	int		tcol;
	int		tline;
	char	*join;
	char	*moves;

	tcol = game->x_player;
	tline = game->y_player;
	valid = valid_move(game, col, line, keycode);
	if (valid != -1)
	{
		moves = ft_itoa(game->move_counter);
		join = ft_join("Move counter : ", moves);
		game->y_player = line;
		game->x_player = col;
		game->map.map[col][line] = 'P';
		game->map.map[tcol][tline] = '0';
		// update_image(keycode, game);
		mlx_string_put(game->mlx, game->window, 32, (game->map.rows + 1) * 32,
			0x00000000, join);
		free (moves);
		free (join);
		ft_printf("Moves: %d\n", game->move_counter++);
		moves = ft_itoa(game->move_counter);
		join = ft_join("Move counter : ", moves);
		mlx_string_put(game->mlx, game->window, 32, (game->map.rows + 1) * 32,
			0x0000FF00, join);
		free (moves);
		free(join);
	}
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	int	col;
	int	line;

	col = game->x_player;
	line = game->y_player;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		line--;
	else if (keycode == KEY_W || keycode == KEY_UP)
		col--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		line++;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		col++;
	else if (keycode == 53)
	{
		printf("** EXIT GAME **");
		ft_exit(game);
	}
	move_player(game, col, line, keycode);
	return (0);
}
