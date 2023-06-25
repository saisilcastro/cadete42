/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:26:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 05:54:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
		*chained = next;
	}
	free(*chained);
}