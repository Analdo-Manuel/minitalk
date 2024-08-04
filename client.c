/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:37:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/02 19:04:23 by analdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	set_message(pid_t pid, unsigned char str)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((str >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
	}
}

pid_t	ft_atoi(char *str)
{
	pid_t	r;

	r = 0;
	while (*str >= '0' && *str <= '9')
		r = r * 10 + (*str++ - '0');
	return (r);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		while (av[2][0])
			set_message(ft_atoi(av[1]), (av[2]++)[0]);
		set_message(ft_atoi(av[1]), (av[2])[0]);
	}
	else
	{
		write(2, "\033[31m\033[1mERROR\033[0m\n", 19);
		exit(1);
	}
	return (0);
}
