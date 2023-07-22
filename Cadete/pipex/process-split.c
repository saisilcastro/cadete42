/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process-split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:49:30 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 18:08:18 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_of.h"

void	process_begin(t_process *process, t_descriptor *descriptor)
{
	if (!process || !process->path || !descriptor)
		return ;
	dup2(descriptor->input, STDIN_FILENO);
	close(descriptor->input);
	dup2(process->fd[1], STDOUT_FILENO);
	close(process->fd[1]);
	printf("%i\n", process_execute(process));
}

void	process_between(t_process *current, t_process *preview)
{
	if (!current || !preview)
		return ;
	dup2(preview->fd[0], STDIN_FILENO);
	close(preview->fd[0]);
	dup2(current->fd[1], STDOUT_FILENO);
	close(current->fd[1]);
	printf("%i\n", process_execute(current));
}

void	process_end(t_process *process, t_descriptor *descriptor)
{
	if (!process || !descriptor)
		return ;
	dup2(process->fd[0], STDIN_FILENO);
	close(process->fd[0]);
	close(process->fd[1]);
	dup2(descriptor->output, STDOUT_FILENO);
	close(descriptor->output);
	printf("%i\n", process_execute(process));
}
