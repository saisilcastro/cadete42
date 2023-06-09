/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:45:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/05 18:03:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

#define ACTIVATED 0
#define POS 1
#define MAX 2

static char	*allocate(char *buffer, int len, int pos, int *activate)
{
	char	*line;

	if (!len)
		return (NULL);
	line = (char *)malloc(len + 1 * sizeof(char));
	if (!line)
	{
		*activate = 0;
		return (NULL);
	}
	ft_strlcpy(line, &buffer[(pos - len) - 1], len + 1);
	return (line);
}

int	loop(char **buffer, int *active, int *pos)
{
	int		len;
	char	*update;

	len = 0;
	update = *buffer;
	while (*(update + *pos))
	{
		if (*(update + *pos) == '\n')
		{
			*pos += 1;
			break ;
		}
		*pos += 1;
		len++;
	}
	if (!len)
	{
		if (*(update + *pos) == '\0')
			return (0);
		*active = 0;
		len = 1;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static int	status[MAX];
	int			len;
	char		buffer[BUFFER_SIZE];
	char		*update;
	char		*line;

	if (status[ACTIVATED] == 0)
	{
		status[ACTIVATED] = 1;
		if (fd && !read(fd, buffer, BUFFER_SIZE))
			return (NULL);	
	}
	printf(" %c ", buffer[status[POS]]);
	update = buffer;
	len = loop(&update, &status[ACTIVATED], &status[POS]);
	if (!len)
		return (NULL);
	line = allocate(update, len, status[POS], &status[ACTIVATED]);
	return (line);
}
