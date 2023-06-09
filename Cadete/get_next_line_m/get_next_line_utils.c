/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:08:36 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/15 17:13:56 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_byte	*byte_get(char set)
{
	t_byte	*byte;

	byte = (t_byte *)malloc(sizeof(t_byte));
	byte->symbol = set;
	byte->next = NULL;
	return (byte);
}

void	byte_next_last(t_byte **head, t_byte *new)
{
	t_byte	*update;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	update = *head;
	while (update->next)
		update = update->next;
	update->next = new;
}

t_file_of	file_start(int fd)
{
	t_file_of	file;

	file.pos = 0;
	file.read = 0;
	file.last = 0;
	file.len = 0;
	file.fd = fd;
	file.done = 0;
	file.line = NULL;
	file.string = NULL;
	return (file);
}
