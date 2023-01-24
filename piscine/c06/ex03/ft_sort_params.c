/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:27:25 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/31 19:27:55 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
}

int	ft_strcmp(char *arg1, char *arg2)
{
	int	i;

	i = 0;
	while ((arg1[i] || arg2[i]) && (arg1[i] == arg2[i]))
		i++;
	return (arg1[i] - arg2[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	if (argc <= 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
		}
	}
	ft_print_params (argc, argv);
	return (0);
}
