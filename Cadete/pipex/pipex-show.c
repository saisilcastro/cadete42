/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:47:09 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/28 23:11:43 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipe_path_show(t_chained *path);
static void	pipe_command_show(t_chained *command);

void	pipe_show(t_pipe *set)
{
	if (!set)
		return ;
	pipe_path_show(set->path);
	pipe_command_show(set->cmd);
}

static void	pipe_path_show(t_chained *path)
{
	while (path)
	{
		printf("Path: %s\n", (char *)path->data);
		path = path->next;
	}
}

static void	pipe_command_show(t_chained *command)
{
	t_chained	*flag;

	while (command)
	{
		printf("Name: %s", ((t_command *)command->data)->name);
		flag = ((t_command *)command->data)->flag;
		while (flag)
		{
			printf(" %s", (char *)flag->data);
			flag = flag->next;
		}
		printf("\n");
		command = command->next;
	}
}
