/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:50:01 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/25 01:53:18 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_pop_str(char *str, int i)
{
	str = &str[i - 1];
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int i, int y)
{
	int	j;
	int	x;

	j = 0;
	while (j < y -1)
	{
		if (s1[j] == s2[i])
		{
			i++;
			j++;
		}
		else
		{
			x = s1[j] - s2[i];
			return (x);
		}
	}
	x = s1[j] - s2[i];
	return (x);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	x;
	int	y;
	int	j;

	j = ft_strlen(str);
	y = ft_strlen(to_find);
	i = 0;
	x = 0;
	while (str[i])
	{
		if (to_find[0] == str[i])
		{
			x = ft_strncmp(to_find, str, i, y);
			i++;
		}
		else if (x == 0)
		{
			return (ft_pop_str(str, i));
		}
		else
			i++;
	}
	return (0);
}
/*
int main()
{
	char a[]="hell heh jhhs shgf ehfu hello hjkdffsg";
	char b[]="hello";
	ft_strstr(a, b);
}
*/
