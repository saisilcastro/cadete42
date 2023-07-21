/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained-next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:30:55 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/01 21:31:42 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chained_of.h>

void	chained_next_first(t_chained **head, t_chained *next)
{
	if (!next)
		return ;
	next->next = *head;
	if (*head)
		(*head)->prev = next;
	*head = next;
}

void	chained_next_last(t_chained **head, t_chained *next)
{
	t_chained	*update;

	if (!next)
		return ;
	if (!*head)
	{
		*head = next;
		return ;
	}
	update = *head;
	while (update->next)
		update = update->next;
	next->prev = update;
	update->next = next;
}
