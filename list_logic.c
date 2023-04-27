/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:35:34 by federico          #+#    #+#             */
/*   Updated: 2023/04/28 01:05:16 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_c_list	*node_init(void)
{
	struct s_c_list	*node;

	node = malloc(sizeof(struct s_c_list));
	if (!node)
		return (NULL);
	node->c = 0;
	node->next = NULL;
	return (node);
}

struct s_c_list	*add_node(struct s_c_list *head, struct s_c_list *node)
{
	struct s_c_list	*current;

	if (!node)
		return (head);
	if (!head)
		return (node);
	current = head;
	while (current->next)
		current = current->next;
	current->next = node;
	return (head);
}


void	print_list(struct s_c_list *node)
{
	char	c;

	while (node && (node->c != '\0'))
	{
		c = node->c;
		write(1, &c, 1);
		node = node->next;
	}
	write(1, "\n", 1);
}

void	free_list(struct s_c_list *head)
{
	struct s_c_list	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
