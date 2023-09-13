/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:20:17 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/12 18:15:11 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_collect_ascia(t_game *game)
{
	game->ascia_collected = 1;
	return (1);
}

int	ft_collect(t_game *game)
{
	int	len;

	len = SPRITE_SIZE;
	game->collectibles--;
	if (game->collectibles == 0)
	{
		mlx_destroy_image(game->mlx, game->map.exit);
		game->map.exit = mlx_xpm_file_to_image(game->mlx, "./img/exitopen.xpm",
				&len, &len);
	}
	return (1);
}

int	valid_move(t_game *game, int col, int line, int key)
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
	else if (game->map.map[col][line] == 'U')
		return (ft_collect_ascia(game));
	else if (game->map.map[col][line] == 'E' && game->collectibles > 0)
		return (-1);
	else if (game->map.map[col][line] == 'A' && game->ascia_collected == 1)
		return (1);
	else if (game->map.map[col][line] == 'A' && game->ascia_collected == 0)
		return (-1);
	else if (game->map.map[col][line] == 'E' && game->collectibles == 0)
	{
		ft_printf("\n\nYOU WIN🏆\n\n");
		ft_exit(game);
	}
	else if (key != KEY_W && key != KEY_S && key != KEY_A && key != KEY_D
		&& key != KEY_UP && key != K_DO && key != K_LE && key != K_RI)
		return (-1);
	return (1);
}

int	move_player(t_game *game, int col, int line, int keycode)
{
	int	valid;
	int	tcol;
	int	tline;

	tcol = game->x_player;
	tline = game->y_player;
	valid = valid_move(game, col, line, keycode);
	if (valid != -1)
	{
		game->y_player = line;
		game->x_player = col;
		game->map.map[col][line] = 'P';
		game->map.map[tcol][tline] = '0';
		game->move_num++;
		ft_printf("Moves: %d\n", game->move_num);
	}
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	int	col;
	int	line;

	col = game->x_player;
	line = game->y_player;
	if (keycode == KEY_A || keycode == K_LE)
		line--;
	else if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		col--;
	else if (keycode == KEY_D || keycode == K_RI)
		line++;
	else if (keycode == KEY_S || keycode == K_DO)
		col++;
	else if (keycode == 53)
	{
		printf("** EXIT GAME **");
		ft_exit(game);
	}
	move_player(game, col, line, keycode);
	return (0);
}
