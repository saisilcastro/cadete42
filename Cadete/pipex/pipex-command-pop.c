/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:26:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 15:01:40 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command-of.h"

void	pipe_command_pop(t_chained **chained)
{
	t_chained	*next;

	if (!*chained)
		return ;
	while (*chained)
	{
		next = (*chained)->next;
		command_pop((*chained)->data);
		free(*chained);
		*chained = next;
	}
}