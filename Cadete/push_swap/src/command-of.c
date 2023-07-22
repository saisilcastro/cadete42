/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:54:55 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/22 02:40:27 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_of.h>

t_command	*command_push(char *data)
{
	t_command	*set;
	int			len;

	if (!data)
		return (NULL);
	set = (t_command *)malloc(sizeof(t_command));
	if (!set)
		return (NULL);
	len = 0;
	while (*(data + len))
		len++;
	set->data = (char *)malloc((len + 1) * sizeof(char));
	*(set->data + len) = '\0';
	len = 0;
	while (*(data + len))
	{
		*(set->data + len) = *(data + len);
		len++;
	}
	set->next = NULL;
	return (set);
}

int	command_next_first(t_command **head, t_command *set)
{
	if (!set)
		return (0);
	if (!*head)
	{
		*head = set;
		return (1);
	}
	set->next = *head;
	*head = set;
	return (1);
}

int	command_next_last(t_command **head, t_command *set)
{
	t_command	*update;

	if (!set)
		return (0);
	if (!*head)
	{
		*head = set;
		return (1);
	}
	update = *head;
	while (update->next)
		update = update->next;
	update->next = set;
	return (1);
}

void	command_pop(t_command **head)
{
	t_command	*next;

	while (*head)
	{
		next = (*head)->next;
		if ((*head)->data)
			free((*head)->data);
		free(*head);
		*head = next;
	}
}
