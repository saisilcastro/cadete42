/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:31:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 18:05:46 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_OF_H
# define PROCESS_OF_H

# include "pipex.h"

typedef struct s_process{
	int		fd[2];
	char	*path;
	char	**flag;
}t_process;

extern t_process	*process_push(char *path, t_chained *flag);
extern int			process_execute(t_process *process);
extern void			process_begin(t_process *process, t_descriptor *descriptor);
extern void			process_between(t_process *current, t_process *preview);
extern void			process_end(t_process *process, t_descriptor *descriptor);
extern void			process_pop(t_process *set);

#endif // PROCESS_OF_H