/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:30 by fbriglia          #+#    #+#             */
/*   Updated: 2023/04/26 17:53:04 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"
void sigaction()
{
	
}

int	main()
{
	struct	sigation	sigs;
	pid_t				pid;

	ft_printf("Starting server...\n");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigs.sa_sigaction = &answer;
	sigs.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigs, NULL);
	sigaction(SIGUSR2, &sigs, NULL);
	sigemptyset(&sigs.sa_mask);
	while (1)
		pause();
}