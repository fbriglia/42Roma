/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:22:32 by fbriglia          #+#    #+#             */
/*   Updated: 2023/08/25 17:03:35 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print_f/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i]
		== '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	send_string(pid_t pid, const char *string)
{
	int	bit;
	int	v;

	while (*string)
	{
		v = *string;
		bit = 0;
		while (bit < 8)
		{
			if ((v & (1 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(1000);
		}
		string++;
	}
}

void	recv(int sign)
{
	(void)sign;
	ft_printf("The message had been sent.\n");
}

int	main(int argc, char const *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		return (ft_printf("Wrong input data"));
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &recv);
	send_string(server_pid, argv[2]);
	send_string(server_pid, "\n");
	return (0);
}
