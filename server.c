/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:54:01 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/01 13:15:23 by almanuel         ###   ########.fr       */
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
	static int		bit;
	static unsigned char	r;

	r |= (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (r == '\0')
			ft_putchar('\n');
		else
			ft_putchar(r);
		bit = 0;
		r = 0;
	}
	else
		r <<= 1;
}

int	main(void)
{
        ft_putnbr(getpid());
        ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_sent_message);
		signal(SIGUSR2, ft_sent_message);
	}
	return (0);
}
