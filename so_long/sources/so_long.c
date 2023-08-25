/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/25 15:44:19 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
	destroy_image(game);
	exit(0);
}

int	close_game(t_game *game)
{
	ft_printf("** EXIT GAME **");
	ft_exit(game);
	exit(0);
	return (0);
}

int	render_image(t_game *game)
{
	put_map(game);
	game->counter_calls++;
	if (game->counter_calls == 2147483646)
		game->counter_calls = 0;
	return (0);
}

void	game_init(t_game *game)
{
	char	*str;
	char	*join;

	put_images(game);
	game->move_counter = 0;
	str = ft_itoa(game->move_counter);
	join = ft_join("Move counter : ", str);
	mlx_string_put(game->mlx, game->window, 32, (game->map.rows + 1) * 32,
		0x0000FF00, str);
	free(str);
	free(join);
	str = ft_itoa(game->collectibles);
	join = ft_join("To collect : ", str);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows + 1) * 32, 0xCFFF04, str);
	free(str);
	free(join);
	mlx_hook(game->window, 17, 0, &close_game, game);
	mlx_hook(game->window, 3, 0, &key_handler, game);
	mlx_loop_hook(game->mlx, &render_image, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("%s", "\n **NO INPUT MAP OR TOO MANY INPUTS** \n\n");
		return (1);
	}
	game.counter_calls = 0;
	ft_valid_name(argv[1]);
	ft_parse_map(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.cols * 32,
			(game.map.rows + 2) * 32, "so_long");
	game_init(&game);
	ft_exit(&game);
	return (0);
}
