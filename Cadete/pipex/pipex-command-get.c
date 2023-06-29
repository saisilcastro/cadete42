/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:32:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 20:06:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command_of.h"

void	pipe_command_get(t_pipe *set, int argc, char **argv)
{
	int	pos;

	if (!set || argc < 5)
		return ;
	pos = 2;
	while (pos < argc - 1)
	{
		pipe_command_break(set, *(argv + pos));
		pos++;
	}
}
