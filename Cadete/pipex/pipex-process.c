/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:45:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 15:23:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "pipex.h"
#include "process_of.h"

static void	process_next(t_pipe *set, char *file, t_chained *flag);

void	pipe_process_get(t_pipe *set)
{
	t_chained	*command;
	t_chained	*path;
	char		file[256];

	if (!set)
		return ;
	command = set->cmd;
	while (command)
	{
		path = set->path;
		while (path)
		{
			path_create(file, path->data, ((t_command *)command->data)->name);
			if (access(file, F_OK) == 0)
			{
				process_next(set, file, ((t_command *)command->data)->flag);
				set->descriptor->max++;
				break ;
			}
			path = path->next;
		}
		command = command->next;
	}
}

static void	process_next(t_pipe *set, char *file, t_chained *flag)
{
	t_process	*process;

	process = NULL;
	if (!set || !file)
		return ;
	process = process_push(ft_strdup(file), flag);
	chained_next_last(&set->process, chained_push(process));
}
