/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:05:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 00:31:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	file_exists(t_pipe *set);
static void	treat_command(t_command *command,
				t_descriptor *descriptor, char *path);

void	pipe_execute(t_pipe *set)
{
	if (!set)
		return ;
	file_exists(set);
}

static void	file_exists(t_pipe *set)
{
	t_chained	*path;
	t_chained	*cmd;
	char		file[256];

	if (!set)
		return ;
	cmd = set->cmd;
	while (cmd)
	{
		path = set->path;
		while (path)
		{
			path_create(file, path->data, ((t_command *)cmd->data)->name);
			if (access(file, F_OK) == 0)
			{
				treat_command(cmd->data, set->descriptor, file);
				break ;
			}
			path = path->next;
		}
		cmd = cmd->next;
	}
}

static void	treat_command(t_command *command,
	t_descriptor *descriptor, char *path)
{
	t_process	process;

	if (!command || !descriptor || !path)
		return ;
	process_start(&process, descriptor);
	process_prepare(&process, command);
	//process_run(&process, path);
	process_pop(&process, chained_max(command->flag) + 2);
}
