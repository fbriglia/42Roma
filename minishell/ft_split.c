# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s)
		return (0);
	if ((len == 0 && start == 0) || (size_t)start >= ft_strlen(s))
	{
		s2 = (char *) malloc(sizeof(char) * 1);
		s2[0] = 0;
		return (s2);
	}
	if (ft_strlen(s) + start < len)
		len = ft_strlen(s + start);
	i = 0;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < len && s[start + i] != '\0' && start <= ft_strlen((char *)s))
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int	check_double_pipe(char const *s, char c)
{
	int	i;
	int	p;

	i = 0;
	while(s[i])
	{
		if (s[i] == c)
		{
			p = i;
			p++;
			while (s[p] == ' ')
				p++;
			if (s[p] == c)
				return(-1);
		}
		i++;
	}
	return (0);
}

int	num_word(char const *s, char c)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	if (check_double_pipe(s, c) == -1)
		return(-1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			p++;
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

int	main(void)
{
	char *str = "echo n |     hageF";
	char **matrix;
	// int		i;

	// i = 0;
	if(num_word(str, '|') == -1)
	{
		printf("zsh: parse error near `|'\n");
		return(1);
	}
	matrix = ft_split(str, '|');
	// while(++i < num_word(str , '|'));
	printf("%s\n", matrix[0]);
	printf("%s\n", matrix[1]);
}