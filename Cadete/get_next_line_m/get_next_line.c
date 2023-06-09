/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:45:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/15 17:20:25 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_file_of	file;
	
	//while (i < FD_SETSIZE)
			
	if (file.fd != fd || file.done)
		file = file_start(fd);
	file_prepare(&file);
	return (file_read_line(&file));
}

char	*file_read_line(t_file_of *set)
{	
	if (!set)
		return (NULL);
	set->pos = set->last;
	while (set->pos < set->read)
	{
		byte_next_last(&set->string, byte_get(*(set->buffer + set->pos)));
		if (*(set->buffer + set->pos) == '\n')
		{
			set->last = set->pos + 1;
			set->done = 1;
			break ;
		}
		set->pos++;
		set->len++;
	}
	file_get_line(set);
	return (set->line);
}

void	file_get_line(t_file_of *set)
{
	t_byte	*next;
	
	if (!set || !set->done)
		return ;
	set->line = (char *)malloc((set->len + 1) * sizeof(char));
	set->len = 0;
	while (set->string)
	{
		next = set->string->next;
		*(set->line + set->len++) = set->string->symbol;
		free(set->string);
		set->string = next;
	}
	*(set->line + set->len) = '\0';
	printf("%s", set->line);
	if (set->pos >= set->read)
		set->len = 0;
}

void	file_prepare(t_file_of *set)
{
	if (!set)
		return ;
	if (set->pos >= set->read)
	{
		set->read = read(set->fd, set->buffer, BUFFER_SIZE);
		if (set->read == -1)
			return ;
	}
}
