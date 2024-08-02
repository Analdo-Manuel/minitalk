/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:54:01 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/02 11:55:02 by analdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(pid_t nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	print_message(int sig, siginfo_t *info, void *c)
{
	static unsigned char	r;
	static unsigned int		i;
	pid_t					pid_cl;

	(void)c;
	r |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (r == '\0')
		{
			ft_putchar('\n');
			pid_cl = info->si_pid;
			kill(pid_cl, SIGUSR1);
		}
		else
			ft_putchar(r);
		i = 0;
		r = 0;
	}
	else
		r <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = print_message;
	sa.sa_flags = SA_SIGINFO;
	write(1, "\033[35m\033[1mBEM_VINDO_AO_SERVIDOR(BONUS)\033[0m\n", 43);
	write(1, "\033[32m\033[1mPID_SERVIDOR -> \033[0m", 30);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
