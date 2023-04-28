/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:36:11 by federico          #+#    #+#             */
/*   Updated: 2023/04/28 16:38:35 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 700
# endif
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

struct s_c_list
{
	struct s_c_list	*next;
	char			c;
};

struct s_c_list	*node_init(void);
struct s_c_list	*add_node(struct s_c_list *head, struct s_c_list *node);
void			print_list(struct s_c_list *node);
void			free_list(struct s_c_list *head);

#endif