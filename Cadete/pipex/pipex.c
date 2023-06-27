/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:07:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 19:46:46 by lde-cast         ###   ########.fr       */
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
}

void	pipe_pop(t_pipe *set)
{
	if (!set)
		return ;
	printf("pipe poping\n");
	pipe_command_pop(&set->cmd);
	chained_pop(&set->path);
	if (set->input)
		free(set->input);
	if (set->output)
		free(set->output);
	close(set->descriptor->input);
	close(set->descriptor->output);
	free(set->descriptor);
}
