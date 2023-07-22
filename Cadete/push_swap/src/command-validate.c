/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:45:40 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/22 02:49:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_of.h>

int	command_validate(t_command *head)
{
	t_command	*update;
	char		*buffer;

	if (!head)
		return (0);
	update = head;
	while (update)
	{
		buffer = update->data;
		if (!buffer)
			return (0);
		while (*buffer && *buffer >= '0' && *buffer <= '9')
			buffer++;
		if (*buffer)
			return (0);
		update = update->next;
	}
	return (1);
}
