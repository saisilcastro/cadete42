/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:32:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 05:52:07 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "pipex.h"
#include "command-of.h"

static void			command_break(t_pipe *set, char *command);
static char			*name_get(char *command, char name[16], int *pos);
static t_chained	*flag_get(char *command, int *pos);
static char *		ft_strdup(char *str);

void	pipe_command_get(t_pipe *set, int argc, char **argv)
{
	int	pos;
	
	if (!set || argc < 5)
		return ;
	pos = 2;
	while (pos < argc - 1)
	{
		command_break(set, *(argv + pos));
		pos++;
	}
}

static void	command_break(t_pipe *set, char *command)
{
	char		buffer[16];
	char		*name;
	int			pos;
	t_chained	*flag;
	
	if (!command || !set)
		return ;
	flag = NULL;
	pos = 0;
	name = name_get(command, buffer, &pos);
	flag = flag_get(command, &pos);
	chained_next_last(&set->cmd, chained_push(command_push(name, flag)));
}

static char	*name_get(char *command, char name[], int *pos)
{
	int		i;
	char	*buffer;

	if (!command)
		return (NULL);
	while (*(command + *pos) == ' ')
		*pos += 1;
	i = 0;
	while (*(command + *pos) && *(command + *pos) != ' ')
	{
		*(name + i) = *(command + *pos);
		*pos += 1;
		i++;
	}
	*(name + i) = '\0';
	while (*(command + *pos) && *(command + *pos) != '-')
		*pos += 1;
	buffer = ft_strdup(name);
	return (buffer);
}

static t_chained	*flag_get(char *command, int *pos)
{
	t_chained	*flag;
	char		buffer[32];
	int			i;

	flag = NULL;
	if (!command || *(command + *pos) == '\0')
		return (NULL);	
	i = 0;
	while (*(command + *pos))
	{
		while (*(command + *pos) && *(command + *pos) == ' ')
			*pos += 1;
		if (*(command + *pos) == '\0')
			break ;
		*(buffer + i) = *(command + *pos);
		if (*(command + *pos) == '-' && i > 0)
		{
			*(buffer + i) = '\0';
			//chained_next_last(&flag, chained_push(buffer));
			i = 0;
		}
		i++;
		*pos += 1;
	}
	if (i > 0)
	{
		*(buffer + i) = '\0';
		printf("***%s\n", buffer);
		chained_next_last(&flag, chained_push(ft_strdup(buffer)));
	}
	return (flag);
}

static char *		ft_strdup(char *str)
{
	char *buffer;
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	buffer = (char *)malloc(len + 1 * sizeof(char));
	len = 0;
	while (*(str + len))
	{
		*(buffer + len) = *(str + len);
		len++;
	}
	*(buffer + len) = '\0';
	return (buffer);
}