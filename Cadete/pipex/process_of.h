/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:31:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/29 00:27:52 by lde-cast         ###   ########.fr       */
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
extern void	process_pop(t_process *set, int max);

#endif // PROCESS_OF_H