/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:59:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 17:38:33 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "chained.h"
# include "descriptor_of.h"
# include "process_of.h"
# include "command_of.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
#include <stdlib.h>

extern char			*ft_strdup(char *str);
extern int			ft_strlen(char *str);
extern void			path_create(char *fpath, char *path, char *app);

typedef struct s_pipe{
	char			*input;
	char			*output;
	t_chained		*cmd;
	t_chained		*path;
	t_descriptor	*descriptor;
	t_chained		*process;
}t_pipe;

extern void			pipe_start(t_pipe *set);
extern void			pipe_file_get(t_pipe *set, int argc, char **argv);
extern void			pipe_command_get(t_pipe *set, int argc, char **argv);
extern void			pipe_command_break(t_pipe *set, char *command);
extern void			pipe_environment_get(t_pipe *set, char **envp);
extern void			pipe_process_get(t_pipe *set);
extern void			pipe_show(t_pipe *set);
extern void			pipe_execute(t_pipe *set);
extern void			pipe_command_pop(t_chained **set);
extern void			pipe_process_pop(t_chained **set);
extern void			pipe_pop(t_pipe *set);

#endif // PIPEX_H
