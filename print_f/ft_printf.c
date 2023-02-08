/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:25:31 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/06 13:38:23 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == '%')
		{
			ft_check(str[i + 1], );
		}
	}
}
// printf("ciau belu %i ciao bello %i ciao bello", counter, temp)
//  malloc, free, write,
// va_start, va_arg, va_copy, va_end
