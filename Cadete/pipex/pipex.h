/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:59:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 22:48:26 by lde-cast         ###   ########.fr       */
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
# include <stdio.h>

extern char			*ft_strdup(char *str);

typedef struct s_pipe{
	char			*input;
	char			*output;
	t_chained		*cmd;
	t_chained		*path;
	t_descriptor	*descriptor;
}t_pipe;

extern void			pipe_start(t_pipe *set);
extern void			pipe_file_get(t_pipe *set, int argc, char **argv);
extern void			pipe_command_get(t_pipe *set, int argc, char **argv);
extern void			pipe_environment_get(t_pipe *set, char **envp);
extern void			pipe_process_execute(t_process *process);
extern void			pipe_execute(t_pipe *set);
extern void			pipe_command_pop(t_chained **set);
extern void			pipe_pop(t_pipe *set);

#endif // PIPEX_H
