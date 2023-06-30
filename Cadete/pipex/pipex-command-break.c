/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-break.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:58:41 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 19:58:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command_of.h"

static char			*space_skip(char *command);
static char			*command_name_get(char *command, char *name);
static void			command_flag_get(char *command, t_chained **flag);

void	pipe_command_break(t_pipe *set, char *argv)
{
	char		name[32];
	char		*arg;
	t_chained	*flag;
	t_command	*command;

	if (!argv || !set)
		return ;
	flag = NULL;
	command = NULL;
	arg = argv;
	arg = command_name_get(arg, name);
	command_flag_get(arg, &flag);
	command = command_push(ft_strdup(name), flag);
	chained_next_last(&set->cmd, chained_push(command));
}

static void	command_flag_get(char *command, t_chained **flag)
{
	char	buffer[128];
	char	*name;
	int		i;

	if (!command)
		return ;
	while (*command)
	{
		i = 0;
		while (*command && *command != ' ')
		{
			*(buffer + i) = *command;
			command++;
			i++;
		}
		if (i > 0)
		{
			*(buffer + i) = '\0';
			name = ft_strdup(buffer);
			chained_next_last(flag, chained_push(name));
			i = 0;
		}
		command = space_skip(command);
	}
}

static char	*command_name_get(char *command, char *name)
{
	int	i;

	i = 0;
	command = space_skip(command);
	while (*command && *command != ' ')
	{
		*(name + i) = *command;
		command++;
		i++;
	}
	*(name + i) = '\0';
	return (command);
}

static char	*space_skip(char *command)
{
	while (*command && *command == ' ')
		command++;
	return (command);
}
