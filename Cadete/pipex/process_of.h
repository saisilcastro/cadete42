/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:31:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/29 15:08:38 by mister-code      ###   ########.fr       */
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
extern void			process_pop(t_process *set);

#endif // PROCESS_OF_H