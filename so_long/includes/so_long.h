/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:26:40 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/12 18:09:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SPRITE_SIZE 16

# define KEY_W 119
# define KEY_A 97  /* U+0061 LATIN SMALL LETTER A */
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define K_LE 65361
# define K_RI 65363
# define K_DO 65364
# define KEY_ESC 65307

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*arbusto;
	void	*ascia;
}			t_map;

typedef struct s_game
{
	t_map	map;
	int		ascia_collected;
	int		collectibles;
	int		x_player;
	int		y_player;
	int		counter_calls;
	int		was_exit;
	char	prev_move;
	char	turn;
	int		x_enemy;
	int		y_enemy;
	int		move_num;
	void	*mlx;
	void	*window;
	int		was_collectible;
	int		p_pov;
	char	*move_counter;
	char	*to_collect;
}			t_game;

int			key_handler(int keycode, t_game *game);
void		put_map(t_game *game);
void		put_images(t_game *game);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_valid_name(char *str);
void		ft_parse_map(t_game *game, char *file);
char		*ft_join(char *s1, char *s2);
int			ft_strlen(char *str);
int			key_handler(int keycode, t_game *game);
int			move_enemy(t_game *game);
char		*ft_itoa(int n);
void		ft_exit(t_game *game);
int			ft_moven(t_game *game, int col, int line);
int			ft_movew(t_game *game, int col, int line);
int			ft_movee(t_game *game, int col, int line);
int			ft_moves(t_game *game, int col, int line);
void		switch_position(t_game *game, int col, int line);
void		update_image_enemy(t_game *game, char direction);
void		ft_check(t_game *game);
void		destroy_image(t_game *game);
int			ft_check_map_pop(t_game *game);
int			close_game(t_game *game);
char		*ft_strdup(char *src);
void		create_map(t_game *game, char *file);
void		find_player_exit(t_game *game);
int			valid(t_game *game, int col, int line);
int			ft_m_straight(t_game *game, int col, int line);


#endif