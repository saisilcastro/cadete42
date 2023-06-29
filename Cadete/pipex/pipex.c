/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:07:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/29 12:54:23 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_start(t_pipe *set)
{
	if (!set)
		return ;
	set->input = NULL;
	set->output = NULL;
	set->cmd = NULL;
	set->path = NULL;
	set->descriptor = (t_descriptor *)malloc(sizeof(t_descriptor));
	set->descriptor->current = 0;
	set->descriptor->max = 0;
	set->descriptor->input = 0;
	set->descriptor->output = 0;
	set->process = NULL;
}

void	pipe_pop(t_pipe *set)
{
	if (!set)
		return ;
	pipe_command_pop(&set->cmd);
	chained_pop(&set->path);
	if (set->input)
		free(set->input);
	if (set->output)
		free(set->output);
	if (set->descriptor)
	{
		if (set->descriptor->input != -1)
			close(set->descriptor->input);
		if (set->descriptor->output != -1)
			close(set->descriptor->output);
		free(set->descriptor);
	}
	pipe_process_pop(&set->process);
}
