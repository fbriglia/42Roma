/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:32:21 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/24 21:15:20 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlen(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i <= size -1)
		{
			dest[i] = src[i];
			i++;
		}
		while (dest[i])
		{
			dest[i] = 0;
			i++;
		}
	}
	return (x);
}
/*
int	main()
{
	char a[50] = "hhfd";
	char b[50] = "ciao come stai";
	printf("%u", ft_strlcpy(a , b, 8));
}
*/
