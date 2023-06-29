/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 23:48:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>

void	execute(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc < 5)
		return (-1);
	execute(argc, argv);
	return (0);
}

void	execute(int argc, char **argv)
{
	t_pipe		pipe;
	extern char	**__environ;

	if (argc != 2)
	{
		pipe_start(&pipe);
		pipe_file_get(&pipe, argc, argv);
		pipe_command_get(&pipe, argc, argv);
		pipe_environment_get(&pipe, __environ);
		//pipe_show(&pipe);
		pipe_execute(&pipe);
		pipe_pop(&pipe);
	}
}
