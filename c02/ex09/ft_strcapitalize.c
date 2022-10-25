/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:16:13 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/24 22:54:47 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	a;

	ft_lowercase(str);
	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && a == 0)
		{
			str[i] -= 32;
			a = 1;
		}
		else if (!(str[i] >= 'a' && str[i] <= 'z') && a == 1)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				a = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9' && a == 0)
			a = 1;
		i++;
	}
	return (str);
}
/*
int main()
{
	char str[500] = "ch78hA./ 	ks/.7S+sSl/. $$s1";
	printf("%s", ft_strcapitalize(str));
}
*/
