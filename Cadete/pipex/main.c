/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 01:02:45 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>

void	execute(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (-1);
	execute(argc, argv, envp);
	return (0);
}

void	execute(int argc, char **argv, char **envp)
{
	t_pipe	pipe;

	if (argc != 2)
	{
		pipe_start(&pipe);
		pipe_file_get(&pipe, argc, argv);
		pipe_command_get(&pipe, argc, argv);
		pipe_environment_get(&pipe, envp);
		pipe_execute(&pipe);
	}
	pipe_pop(&pipe);
}
