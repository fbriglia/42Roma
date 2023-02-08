/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:05:07 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/01 13:05:07 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_word(char const *s, char c)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i] == 0)
				return (p);
			i++;
			if (s[i] == 0)
				return (p);
		}
		if (s[i] && s[i] != c)
		{
			p += 1;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (p);
}

int	len_word(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	return (j);
}

char	**ft_writing(char **matrix, const char *s, char c)
{
	int	i;
	int	p;
	int	k;
	int	start;

	k = 0;
	p = 0;
	i = 0;
	while ((size_t)i < ft_strlen((char *)s))
	{
		if (s[i] != c)
		{
			start = i;
			p = len_word(s, c, start);
			matrix[k] = ft_substr(s, start, p);
			k++;
			i += p;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;

	i = 0;
	if (!s)
		return (0);
	matrix = malloc((num_word(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (0);
	matrix[num_word(s, c)] = NULL;
	return (matrix = ft_writing(matrix, s, c));
	return (matrix);
}
