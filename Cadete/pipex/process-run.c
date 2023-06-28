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

static void	process_begin(t_process *set, char *path);
static void	process_between(t_process *set, char *path);
static void	process_end(t_process *set, char *path);
void		process_execute(t_process *set, char *path);

void	process_run(t_process *set, char *path)
{
	if (!set || !path)
		return ;
	if (set->descriptor->current == 0)
		process_begin(set, path);
	else if (set->descriptor->current == set->descriptor->max - 1)
		process_end(set, path);
	else
		process_between(set, path);
	set->descriptor->current++;
}

static void	process_begin(t_process *set, char *path)
{
	if (!set || !path)
		return ;
	dup2(set->descriptor->input, INFILE);
	dup2(set->descriptor->output, OUTFILE);
	process_execute(set, path);
}

static void	process_between(t_process *set, char *path)
{
	if (!set || !path)
		return ;
}

static void	process_end(t_process *set, char *path)
{
	if (!set || !path)
		return ;
	dup2(set->descriptor->input, INFILE);
	dup2(set->descriptor->output, OUTFILE);
	process_execute(set, path);
}

void	process_execute(t_process *set, char *path)
{
	char	**nothing;

	set->descriptor->aux = fork();
	if (!set || !path || set->descriptor->aux == -1)
		return ;
	if (set->descriptor->aux == 0)
	{
		nothing = NULL;
		execve(path, set->flag, nothing);
	}
}
