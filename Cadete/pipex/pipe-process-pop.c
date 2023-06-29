/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe-process-pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:52:11 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 12:57:26 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_process_pop(t_chained **process)
{
	t_chained	*next;

	if (!*process)
		return ;
	while (*process)
	{
		next = (*process)->next;
		process_pop((*process)->data);
		free(*process);
		*process = next;
	}
}
