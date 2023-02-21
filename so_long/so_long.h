/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:25:48 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/21 18:59:27 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*clean_end(char *line_sporca);
char	*clean_start(char *line_sporca);
char	*ft_join(char *s1, char *s2);
char	*create_line(int fd, char *statica);
int		ft_valid_name(char *str);
int		ft_strcmp(const char *s1, const char *s2);


# endif
#endif