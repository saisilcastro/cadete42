/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:07:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/18 18:21:50 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_chained	*chained_set(void *data)
{
	t_chained	*set;

	set = (t_chained *)malloc(sizeof(t_chained));
	if (!set)
		return (NULL);
	set->data = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

void	chained_next_last(t_chained **head, t_chained *next)
{
	t_chained	*update;

	if (!*head)
	{
		*head = next;
		return ;
	}
	update = *head;
	while (update->next)
		update = update->next;
	update->next = next;
}

void	chained_delete(t_chained **head)
{
	t_chained	*remover;
	t_chained	*next;

	remover = *head;
	while (remover)
	{
		next = remover->next;
		free(remover);
		remover = next;
	}
}

void	pipex_start(t_pipex *set)
{
	if (!set)
		return ;
	set->input = NULL;
	set->output = NULL;
	set->cmd = NULL;
}
