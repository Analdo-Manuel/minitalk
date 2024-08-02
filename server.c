/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:54:01 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/02 11:35:01 by analdo           ###   ########.fr       */
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

void	ft_sent_message(int sig)
{
	static unsigned char	r;
	static unsigned int		i;

	r |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (r == '\0')
			ft_putchar('\n');
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
	write(1, "\033[36m\033[1mBEM_VINDO_AO_SERVIDOR\033[0m\n", 36);
	write(1, "\033[32m\033[1mPID_SERVER -> \033[0m", 28);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_sent_message);
		signal(SIGUSR2, ft_sent_message);
	}
	return (0);
}
