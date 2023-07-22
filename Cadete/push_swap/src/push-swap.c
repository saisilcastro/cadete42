/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/22 02:50:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <command_of.h>

void	push_swap(char **argv)
{
	t_command	*head;

	head = NULL;
	argv++;
	while (*argv)
	{
		command_next_last(&head, command_push(*argv));
		argv++;
	}
	if (!command_validate(head))
		write(2, "Error\n", 6);
	command_pop(&head);
}
