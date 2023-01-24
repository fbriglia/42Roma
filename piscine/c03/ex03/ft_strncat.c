/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:44:00 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/25 01:56:25 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	if (!dest && !src)
		return (0);
	while (dest[j])
		j++;
	while (src[i] && i <= nb)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	return (dest);
}
/*
int	main()
{
	char    a[6] = "hello";
	char    b[11]="fozza";
}
*/
