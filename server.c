/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:50:25 by federico          #+#    #+#             */
/*   Updated: 2023/04/28 18:01:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

struct s_c_list	*add_bit(int bit)
{
	static int					bit_pos;
	static struct s_c_list		*c;

	sleep(0.000001);
	if (!bit_pos || bit_pos == 1)
	{
		c = node_init();
		if (!c)
			exit(1);
		bit_pos = 1;
	}
	c->c = c->c | (bit_pos * bit);
	if (bit_pos == 128)
	{
		bit_pos = 1;
		return (c);
	}
	bit_pos = bit_pos << 1;
	return (NULL);
}

void	ft_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static struct s_c_list	*list;
	struct s_c_list			*temp_node;

	(void)sig;
	(void)ucontext;
	temp_node = NULL;
	if (info->si_signo == SIGUSR1)
		temp_node = add_bit(0);
	else if (info->si_signo == SIGUSR2)
		temp_node = add_bit(1);
	if (temp_node)
		list = add_node(list, temp_node);
	if (temp_node && temp_node->c == 0)
	{
		print_list(list);
		kill(info->si_pid, SIGUSR1);
		free_list(list);
		list = NULL;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &ft_sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server pid = %u\n", getpid());
	while (1)
		pause();
}
