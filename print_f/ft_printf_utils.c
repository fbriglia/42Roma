/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:20:05 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/13 11:35:30 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i)
{
	int		len;

	len = 0;
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		len += write (1, "-", 1);
		i *= -1;
	}
	if (i > 9)
		len += ft_putnbr(i / 10);
	len += ft_putchar(i % 10 + 48);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_p_base(unsigned int nb, int base, char *bs)
{
	int	len;

	len = 0;
	if (nb >= (unsigned)base)
		len += ft_p_base(nb / base, base, bs);
	len += ft_putchar(bs[nb % base]);
	return (len);
}
