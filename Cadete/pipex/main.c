/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 07:18:07 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>

void	execute(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc < 3)
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
		pipe_process_get(&pipe);
		pipe_execute(&pipe);
		pipe_pop(&pipe);
	}
}
