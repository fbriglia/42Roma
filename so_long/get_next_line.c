/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:14:46 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/16 15:27:07 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*clean_end(char *line_sporca)
{
	int		i;
	int		j;
	char	*statica_pulita;

	i = 0;
	while (line_sporca[i] != '\n' && line_sporca[i])
		i++;
	if (!line_sporca[i])
	{
		free(line_sporca);
		return (NULL);
	}
	statica_pulita = (char *)malloc((ft_strlen(line_sporca) - i + 1)
			* sizeof(char));
	if (!statica_pulita)
		return (0);
	i++;
	j = 0;
	while (line_sporca[i])
		statica_pulita[j++] = line_sporca[i++];
	statica_pulita[j] = '\0';
	free(line_sporca);
	return (statica_pulita);
}

char	*clean_start(char *line_sporca)
{
	int		j;
	char	*line_pulita;

	j = 0;
	if (!line_sporca[j])
		return (NULL);
	while (line_sporca[j] != '\n' && line_sporca[j])
		j++;
	line_pulita = (char *)malloc((j + 2));
	if (!line_pulita)
		return (NULL);
	j = 0;
	while (line_sporca[j] != '\n' && line_sporca[j])
	{
		line_pulita[j] = line_sporca[j];
		j++;
	}
	if (line_sporca[j] == '\n')
	{
		line_pulita[j] = line_sporca[j];
		j++;
	}
	line_pulita[j] = '\0';
	return (line_pulita);
}

char	*create_line(int fd, char *statica)
{
	char	*buff;
	int		k;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	k = 1;
	while (!(ft_strchr(statica, '\n')) && k > 0)
	{
		k = read(fd, buff, BUFFER_SIZE);
		if (k == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[k] = '\0';
		statica = ft_join(statica, buff);
	}
	free(buff);
	return (statica);
}

char	*get_next_line(int fd)
{
	static char	*statica;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	statica = create_line(fd, statica);
	if (!statica)
		return (NULL);
	next_line = clean_start(statica);
	statica = clean_end(statica);
	return (next_line);
}
