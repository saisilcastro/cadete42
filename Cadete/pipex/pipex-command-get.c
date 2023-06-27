/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:32:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 22:49:14 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command-of.h"

static void			command_break(t_pipe *set, char *command);
static char			*name_get(char *command, char name[], int *pos);
static t_chained	*flag_get(t_descriptor *descriptor,
						char *command, int *pos);

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
	flag = flag_get(set->descriptor, command, &pos);
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

static void	command_loop(t_descriptor *descriptor, char *command
	, int *pos, t_chained **flag)
{
	char		buffer[64];
	int			i;

	flag = NULL;
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
			descriptor->max++;
			chained_next_last(flag, chained_push(ft_strdup(buffer)));
			i = 0;
		}
		i++;
		*pos += 1;
	}
}

static t_chained	*flag_get(t_descriptor *descriptor, char *command, int *pos)
{
	t_chained	*flag;
	char		buffer[32];
	int			i;

	flag = NULL;
	if (!command || *(command + *pos) == '\0')
		return (NULL);
	command_loop(descriptor, command, pos, &flag);
	if (i > 0)
	{
		*(buffer + i) = '\0';
		descriptor->max++;
		chained_next_last(&flag, chained_push(ft_strdup(buffer)));
	}
	return (flag);
}
