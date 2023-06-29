/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:16:16 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 16:51:12 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_begin(t_process *set, t_descriptor *descriptor);
static void	process_between(t_process *current, t_process *preview);
static void	process_end(t_process *set, t_descriptor *descriptor);
void	process_execute(t_process *process);

void	pipe_execute(t_pipe *set)
{
	t_chained	*chained;
	t_process	*process;

	if (!set)
		return ;
	chained = set->process;
	while (chained && set->descriptor->current < set->descriptor->max)
	{
		process = chained->data;
		if (pipe(process->fd) == -1)
			break ;
		if (set->descriptor->current == 0)
			process_begin(process, set->descriptor);
		else if (set->descriptor->current == set->descriptor->max - 1)
			process_end(process, set->descriptor);
		else
			process_between(process, chained->prev->data);
		set->descriptor->current++;
		chained = chained->next;
	}
}

static void	process_begin(t_process *process, t_descriptor *descriptor)
{
	if (!process || !process->path || !descriptor)
		return ;
	dup2(descriptor->input, STDIN_FILENO);
	close(descriptor->input);
	printf("begin %i %i\n", process->fd[0], process->fd[1]);
	dup2(process->fd[1], STDOUT_FILENO);
	close(process->fd[1]);
	//process_execute(process);
}

static void	process_between(t_process *current, t_process *preview)
{
	if (!current || !preview)
		return ;
	printf("between\n");
	dup2(preview->fd[0], STDIN_FILENO);
	close(preview->fd[0]);
	dup2(current->fd[1], STDOUT_FILENO);
	close(current->fd[1]);
	//process_execute(current);
}

static void	process_end(t_process *process, t_descriptor *descriptor)
{
	if (!process || !descriptor)
		return ;
	printf("end\n");
	dup2(process->fd[0], STDIN_FILENO);
	close(process->fd[0]);
	dup2(descriptor->output, STDOUT_FILENO);
	//process_execute(process);
}

void	process_execute(t_process *process)
{
	extern char	**__environ;
	int			id;

	id = fork();
	if (!process || !process->path || id == -1)
		return ;
	if (id == 0)
	{
		printf("*****%s\n", process->path);
		//execve(process->path, process->flag, __environ);
	}
}
