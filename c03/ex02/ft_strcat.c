/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:36:40 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/25 01:55:16 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!dest && !src)
		return (0);
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	return (dest);
}
/*
   int main()
   {
   char	a[6] = "hello";
   char	b[11]="fozza";
   ft_strcat(b, a);
   }
   */
