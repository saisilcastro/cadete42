/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:16:16 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/21 18:09:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			process_end(chained->prev->data, set->descriptor);
		else
			process_between(process, chained->prev->data);
		set->descriptor->current++;
		chained = chained->next;
	}
}

int	parent_process(pid_t id)
{
	int	status;

	while (1)
	{
		if (waitpid(id, &status, WUNTRACED | WCONTINUED) == -1)
			return (-1);
		if (WEXITSTATUS(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			return (WIFSIGNALED(status));
		else if (WIFSTOPPED(status))
			return (WIFSTOPPED(status));
		else if (WIFCONTINUED(status))
			return (WIFCONTINUED(status));
		if (!WIFEXITED(status) && !WIFSIGNALED(status))
			exit(EXIT_SUCCESS);
	}
	return (0);
}

int	process_execute(t_process *process)
{
	extern char	**__environ;
	int			id;

	id = fork();
	if (!process || !process->path || id == -1)
		return (id);
	if (id == 0)
		return (execve(process->path, process->flag, __environ));
	else
		parent_process(id);
	return (0);
}
