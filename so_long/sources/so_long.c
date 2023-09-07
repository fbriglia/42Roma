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
	while (y < game->map.rows)
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
	destroy_image(game);
	free(game->mlx);
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
	char	*str;

	str = ft_itoa(game->collectibles);
	// mlx_clear_window(game->mlx, game->window);
	game->counter_calls++;
	if (game->counter_calls == 2147483646)
		game->counter_calls = 0;
	game->to_collect = ft_join("To collect : ", str);
	free(str);
	str = ft_itoa(game->move_num);
	game->move_counter = ft_join("Move Counter: ", str);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows * 2 + 1) * 32, 0xCFFF04, game->move_counter);
	mlx_string_put(game->mlx, game->window, ((game->map.rows*2+1) - 4) * 32,
		(game->map.rows * 2 + 1) * 32, 0xCFFF04, game->to_collect);
	free(game->to_collect);
	free(game->move_counter);
	free(str);
	put_map(game);
	return (0);
}

void	game_init(t_game *game)
{
	// char	*str;
	// char	*join;

	put_images(game);
	// str = ft_itoa(game->move_num);
	// join = ft_join("Move counter : ", str);
	// mlx_string_put(game->mlx, game->window, 64, (game->map.rows * 2 + 1) * 64,
	// 	0x0000FF00, join);
	// free(str);
	// free(join);
	// str = ft_itoa(game->collectibles);
	// join = ft_join("To collect : ", str);
	// free(str);
	// free(join);
	mlx_hook(game->window, 17, 0, &close_game, game);
	mlx_key_hook(game->window, &key_handler, game);
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
	game.prev_move = '0';
	game.move_num = 0;
	game.move_counter = NULL;
	game.ascia_collected = 0;
	game.counter_calls = 0;
	ft_valid_name(argv[1]);
	ft_parse_map(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.cols * 64,
			(game.map.rows + 1) * 64, "so_long");
	game_init(&game);
	ft_exit(&game);
	return (0);
}
