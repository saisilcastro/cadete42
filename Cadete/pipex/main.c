/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 22:52:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>

void	execute(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	execute(argc, argv, envp);
	return (0);
}

//void name_get(void *data)
//{
//	if (!data)
//		return ;
//	char *parameter[] = {NULL, "-l"};
//	char	*do_nothing[] = {NULL};
//	pipe_process_execute("/bin", "ls", parameter, do_nothing);
//}

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
