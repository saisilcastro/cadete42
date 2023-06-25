/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:07:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:07 by mister-code      ###   ########.fr       */
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
}
