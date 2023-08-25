/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:44:36 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/13 11:30:48 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pt(unsigned long nb)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_pointer(nb, "0123456789abcdef");
	return (len);
}

int	ft_pointer(unsigned long nb, char *bs)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_pointer(nb / 16, bs);
	len += ft_putchar(bs[nb % 16]);
	return (len);
}
