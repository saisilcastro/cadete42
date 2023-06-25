/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:59:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 16:11:21 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "chained.h"
#include "command-of.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_pipe t_pipe;
struct s_pipe{
	char		*input;
	char		*output;
	t_chained	*cmd;
	t_chained	*path;
};

extern void			pipe_start(t_pipe *set);
extern void			pipe_file_get(t_pipe *set, int argc, char **argv);
extern void			pipe_command_get(t_pipe *set, int argc, char **argv);
extern int			pipe_process(void *, void (*child_get)(void *, char **), char **);
extern void			pipe_process_execute(const char *path, char *app, char **parameter, char **unknown);
extern void			pipe_command_pop(t_chained **set);
extern void			pipe_pop(t_pipe *set);

#endif // PIPEX_H