/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:59:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 04:36:13 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "chained.h"
#include "command-of.h"
#include <unistd.h>

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
extern void			pipe_command_pop(t_chained **set);
extern void			pipe_pop(t_pipe *set);

#endif // PIPEX_H