/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/23 13:26:59 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <command_of.h>

void	push_swap(char **argv)
{
	t_command	*head;
	t_list		list;

	head = NULL;
	argv++;
	list_set(&list);
	while (*argv)
	{
		command_get(&head, *argv);
		argv++;
	}
	if (!command_validate(head, &list))
	{
		command_pop(&head);
		ft_printf("Error\n");
	}
	else
		list_sort(&list);
	list_pop(&list);
}
