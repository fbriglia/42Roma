/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:33 by fbriglia          #+#    #+#             */
/*   Updated: 2023/04/26 17:53:00 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int	ft_atoi(char *str)
{
	// transform PID in int
}
void	ft_message(int bit_c, int pid, char c)
{
	while(bit_c < 8)
	{
		if (c & (1 << bit_c) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_c ++;
	}
}

void	ft_check_char(int PID, char *message)
{
	int i;
	int bit_c;
	
	i = 0
	while(message[i])
	{
		bit_c = 0;
		ft_message(bit_c, PID, message[i]);
		i++;
	}
}

int	main()
{
	pid_t	c;
	
	c = 0;
	if (argc != 3)
	{
		ft_printf("Too many or few arguments\n");
		ft_printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", argv[0])
		exit(0);
	}
	c = ft_atoi(argv[1]);
	signal(SIGUSR1, &message_check);
	ft_check_char(c, argv[2]);
	ft_message('\n', 0, c);
	ft_message('\0', 0, c);
}