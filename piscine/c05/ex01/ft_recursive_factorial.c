/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:04:19 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/26 12:04:38 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (ft_recursive_factorial(nb -1) * nb);
}
/*
int main ()
{
	ft_recursive_factorial(5);
}
*/
