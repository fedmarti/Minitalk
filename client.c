/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:54:16 by federico          #+#    #+#             */
/*   Updated: 2023/04/28 17:58:44 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

int	g_server_pid;

int	ft_atou(char *str)
{
	unsigned long	n;
	int				i;

	i = 0;
	n = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '+')
		return (-1);
	else
		return ((int)ft_atou(&str[i]));
}

void	conf_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)sig;
	if (info->si_signo == SIGUSR1 && info->si_pid == g_server_pid)
	{
		ft_printf("\nMessage recieved :)\n");
		exit(0);
	}
	else if (info->si_pid != g_server_pid)
		ft_printf("\nWtf?\n");
}

void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (j <= 128)
		{
			if (j & str[i])
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
			j = j << 1;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		pause();
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("\nI only work with two arguments man...");
		ft_printf("\nDude... Just give me the server PID and the message");
		return (1);
	}
	g_server_pid = check_pid(argv[1]);
	if (g_server_pid < 0)
	{
		ft_printf("\nInvalid PID");
		return (1);
	}
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &conf_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	send_message(g_server_pid, argv[2]);
	sleep(1);
	ft_printf("\nServer didn't respond :'0");
	return (1);
}
