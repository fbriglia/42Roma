/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:56:54 by fbriglia          #+#    #+#             */
/*   Updated: 2023/02/13 11:32:35 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

int	ft_printf(const char *str, ...);
int	ft_putnbr(int i);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_p_base(unsigned int nb, int base, char *bs);
int	ft_print_pt(unsigned long nb);
int	ft_pointer(unsigned long nb, char *bs);

#endif