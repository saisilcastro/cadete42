/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained-of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:02:33 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 21:40:14 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:41:13 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/28 22:23:14 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chained_of.h"
#include <stdlib.h>

static void	chained_function(t_chained *set);

t_chained	*chained_push(void *data)
{
	t_chained	*set;

	set = (t_chained *)malloc(sizeof(t_chained));
	if (!set)
		return (NULL);
	set->data = data;
	set->prev = NULL;
	set->next = NULL;
	chained_function(set);
	return (set);
}

int	chained_max(t_chained *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	chained_pop(t_chained **head)
{
	t_chained	*next;
	t_chained	*current;

	current = *head;
	while (current)
	{
		next = current->next;
		if (current->data)
			free(current->data);
		free(current);
		current = next;
	}
}

static void	chained_function(t_chained *set)
{
	if (!set)
		return ;
	set->next_first = chained_next_first;
	set->next_last = chained_next_last;
	set->destroy = NULL;
}
