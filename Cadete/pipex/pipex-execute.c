/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:05:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/26 22:42:35 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	file_exists(t_pipe *set);
static void	command_run(void *path, void *command);

void	pipe_execute(t_pipe *set)
{
	if (!set)
		return ;
	file_exists(set);
}

static void	treat_command(t_command *command, char *path)
{
	if (!command)
		return ;
}

static void	file_exists(t_pipe *set)
{
	t_chained	*path;
	t_chained	*cmd;
	char		file[256];

	if (!set)
		return ;
	path = set->path;
	while (path)
	{
		cmd = set->cmd;
		while (cmd)
		{
			sprintf(file, "%s/%s", (char *)path->data,
				((t_command *)cmd->data)->name);
			if (access(file, F_OK) == 0)
				treat_command(cmd->data, path->data);
			cmd = cmd->next;
		}
		path = path->next;
	}
}

//pipe_process_execute(path, command->name, blood);
static void	command_run(void *path, void *data)
{
	t_command	*command;
	t_chained	*flag;

	if (!path || !data)
		return ;
	command = data;
	printf("**%s**** ", (char *)path);
	flag = command->flag;
	while (flag)
	{
		printf("%s ", (char *)flag->data);
		flag = flag->next;
	}
	printf("\n");
}
