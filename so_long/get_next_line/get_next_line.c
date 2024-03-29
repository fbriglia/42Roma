/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:31:42 by fbriglia          #+#    #+#             */
/*   Updated: 2023/09/12 18:32:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buff)
{
	char	*temp;

	temp = ft_join(str, buff);
	free(str);
	return (temp);
}

char	*clean_end(char *line_sporca)
{
	int		i;
	int		j;
	char	*stat_p;

	i = 0;
	if (!line_sporca)
	{
		free(line_sporca);
		return (NULL);
	}
	while (line_sporca[i] != '\n' && line_sporca[i])
		i++;
	stat_p = (char *)malloc((ft_strlen(line_sporca) - i + 1) * sizeof(char));
	if (!stat_p)
		return (0);
	if (!line_sporca[0])
		i = 0;
	else
		i++;
	j = 0;
	while (ft_strlen(line_sporca) > i)
		stat_p[j++] = line_sporca[i++];
	stat_p[j] = '\0';
	free(line_sporca);
	return (stat_p);
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
	line_pulita = (char *)malloc((j + 1));
	if (!line_pulita)
		return (NULL);
	j = 0;
	while (line_sporca[j] != '\n' && line_sporca[j])
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

	if (!statica)
	{
		statica = (char *)malloc((1) * sizeof(char));
		statica[0] = '\0';
	}
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
		statica = ft_free(statica, buff);
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
