/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:31:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/27 22:43:40 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_OF_H
# define PROCESS_OF_H

# include "pipex.h"
# include "command_of.h"

typedef struct s_process{
	t_descriptor	*descriptor;
	char			*path;
	char			**flag;
}t_process;

extern void	process_start(t_process *set, t_descriptor *descriptor);
extern void	process_prepare(t_process *set, t_command *command);
extern void	process_run(t_process *set, char *path);
extern void	process_pop(t_process *set);

#endif // PROCESS_OF_H