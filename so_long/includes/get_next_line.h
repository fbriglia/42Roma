/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:16:31 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/24 18:12:45 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*clean_end(char *line_sporca);
char	*clean_start(char *line_sporca);
char	*ft_join(char *s1, char *s2);
char	*create_line(int fd, char *statica);

#endif