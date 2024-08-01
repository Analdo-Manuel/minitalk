/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/01 17:21:03 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void     ft_pri_message(pid_t PID, unsigned char str)
{
	unsigned int i;

	i = 8;
	while (i--)
	{
		if ((str >> i) & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(80);
	}
}

pid_t	ft_atoi(char *str)
{
	pid_t	r = 0;

	while (*str >= '0' && *str <= '9')
		r = r * 10 + (*str++ - '0');
	return (r);
}

void	ft_confirmation(int sig)
{
        if (sig == SIGUSR1)
        {
	  write(1, "SUCCESS\n", 8);
	  exit(0);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if ( ac == 3)
	{
		pid = getpid();
		printf("%d\n", pid);
		while (av[2][0])
			ft_pri_message(ft_atoi(av[1]), (av[2]++)[0]);
		signal(SIGUSR1, ft_confirmation);
		ft_pri_message(ft_atoi(av[1]), (av[2])[0]);
		usleep(100000);
		write(2, "\033[1m\033[31mERROR\033[0m\n", 20);
		exit(1);
	}
	return (0);
}
