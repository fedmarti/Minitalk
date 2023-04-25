/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:50:25 by federico          #+#    #+#             */
/*   Updated: 2023/04/26 00:08:34 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

char	c;

void	check_char(void)
{
	if (!c)
		exit(0);
	else
		write(1, &c, 1);
}

void	add_bit(int	bit)
{
	static int	bit_pos;

	if (!bit_pos || bit_pos == 1)
	{
		c = 0;
		bit_pos = 1;
	}
	c = c | (bit_pos * bit);
	if (bit_pos == 10000000)
	{
		bit_pos = 1;
		check_char();
	}
	else
		bit_pos = bit_pos << 1;	
}

void	handle_sigusr1(void)
{
	add_bit(0);
}

void	handle_sigusr2(void)
{
	add_bit(1);
}

int	main()
{
	sigaction(SIGUSR1, &handle_sigusr1);
	sigaction(SIGUSR2, &handle_sigusr2);

	ft_printf("pid = %u", getgid());
	pause()
}