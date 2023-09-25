/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:53 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/14 16:47:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.player);
	mlx_destroy_image(game->mlx, game->map.floor);
	mlx_destroy_image(game->mlx, game->map.wall);
	if (game->enemy == 1)
		mlx_destroy_image(game->mlx, game->map.enemy);
	mlx_destroy_image(game->mlx, game->map.coin);
	mlx_destroy_image(game->mlx, game->map.exit);
	if (game->ascia == 1)
		mlx_destroy_image(game->mlx, game->map.ascia);
	if (game->arbusto == 1)
		mlx_destroy_image(game->mlx, game->map.arbusto);
	mlx_destroy_window(game->mlx, game->window);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	put_images(t_game *game)
{
	int	len;

	len = 32;
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &len,
			&len);
	game->map.player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm",
			&len, &len);
	game->p_pov = 0;
	game->map.floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &len,
			&len);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &len,
			&len);
	game->map.coin = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm", &len,
			&len);
	if (game->enemy == 1)
		game->map.enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm", &len,
				&len);
	game->map.arbusto = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &len,
			&len);
	game->map.ascia = mlx_xpm_file_to_image(game->mlx, "./img/ascia.xpm", &len,
			&len);
}

void	mlx_put_image(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'A')
		mlx_put_image_to_window(game->mlx, game->window, game->map.wall, x * 64,
			y * 64);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->map.floor, x
			* 64, y * 64);
	if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->map.player, x
			* 64, y * 64);
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->map.exit, x * 64,
			y * 64);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->map.coin, x * 64,
			y * 64);
	if (game->enemy == 1 && game->map.map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy, x
			* 64, y * 64);
	if (game->map.map[y][x] == 'U')
		mlx_put_image_to_window(game->mlx, game->window, game->map.ascia, x
			* 64, y * 64);
}

void	put_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->counter_calls % 60 == 0 && game->enemy == 1)
		move_enemy(game);
	while (y < game->map.rows)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			mlx_put_image(x, y, game);
			x++;
		}
		y++;
	}
}
