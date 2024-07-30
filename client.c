#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void     ft_pri_message(pid_t PID, unsigned char str)
{
	int i;

	i = 8;
	while (i--)
	{
		if ((str >> i) & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(10);
	}
}

pid_t	ft_atoi(char *str)
{
	pid_t	r = 0;

	while (*str >= '0' && *str <= '9')
		r = r * 10 + (*str++ - '0');
	return (r);
}
int	main(int ac, char **av)
{
	if ( ac == 3)
	{
		while (av[2][0])
			ft_pri_message(ft_atoi(av[1]), (av[2]++)[0]);
		ft_pri_message(ft_atoi(av[1]), (av[2])[0]);
	}
	return (0);
}
