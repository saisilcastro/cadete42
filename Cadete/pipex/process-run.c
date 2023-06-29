/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process-run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:45:26 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/27 17:01:59 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define INFILE 0
#define OUTFILE 1

static void	process_begin(t_process *set, char *path, int *fd);
static void	process_between(t_process *set, char *path, int *fd);
static void	process_end(t_process *set, char *path, int *fd);
void		process_execute(t_process *set, char *path);

void	process_run(t_process *set, char *path)
{
	int	fd[2];

	if (!set || !path || pipe(fd))
		return ;
	if (set->descriptor->current == 0)
		process_begin(set, path, fd);
	else if (set->descriptor->current == set->descriptor->max - 1)
		process_end(set, path, fd);
	else
		process_between(set, path, fd);
	set->descriptor->current++;
}

static void	process_begin(t_process *set, char *path, int *fd)
{
	if (!set || !path)
		return ;
	dup2(set->descriptor->input, INFILE);
	close(set->descriptor->input);
	dup2(fd[1], OUTFILE);
	process_execute(set, path);
}

static void	process_between(t_process *set, char *path, int *fd)
{
	if (!set || !path)
		return ;
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
}

static void	process_end(t_process *set, char *path, int *fd)
{
	if (!set || !path)
		return ;
	dup2(fd[0], INFILE);
	close(fd[0]);
	dup2(set->descriptor->output, OUTFILE);
	process_execute(set, path);
}

void	process_execute(t_process *set, char *path)
{
	extern char	**__environ;
	int			id;

	id = fork();
	if (!set || !path || id == -1)
		return ;
	if (id == 0)
		execve(path, set->flag, __environ);
}
