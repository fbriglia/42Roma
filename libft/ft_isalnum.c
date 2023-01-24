/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:00:20 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/24 21:10:35 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
			i++;
        else if (str[i] >= '0' && str[i] <= '9')
            i++;
		else
			return (0);
	}
	return (1);
}