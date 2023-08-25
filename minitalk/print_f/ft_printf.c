/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:25:31 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/24 16:41:00 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += (ft_putnbr(va_arg(args, int)));
	else if (c == 's')
		len += (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		len += (ft_putchar(va_arg(args, int)));
	else if (c == 'u')
		len += (ft_p_base(va_arg(args, unsigned int), 10, "0123456789"));
	else if (c == 'p')
		len += ft_print_pt(va_arg(args, unsigned long));
	else if (c == 'x')
		len += (ft_p_base(va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (c == 'X')
		len += (ft_p_base(va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	args;

	i = 0;
	x = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			x += ft_check(str[i + 1], args);
			i++;
		}
		else
			x += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (x);
}
