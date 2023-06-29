/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:26:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 21:54:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command_of.h"

void	pipe_command_pop(t_chained **chained)
{
	t_chained	*next;

	if (!*chained)
	{
		printf("there is no command\n");
		return ;
	}
	while (*chained)
	{
		next = (*chained)->next;
		command_pop((*chained)->data);
		free(*chained);
		*chained = next;
	}
}
