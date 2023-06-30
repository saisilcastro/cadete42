/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:32:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 07:12:05 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command_of.h"

void	pipe_command_get(t_pipe *set, int argc, char **argv)
{
	int	pos;

	if (!set)
		return ;
	pos = 2;
	while (pos < argc - 1)
	{
		pipe_command_break(set, *(argv + pos));
		pos++;
	}
}
