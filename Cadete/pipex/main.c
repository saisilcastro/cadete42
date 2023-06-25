/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 04:40:48 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void show(t_pipe *pipe);

int	main(int argc, char **argv)
{
	t_pipe	pipe;
	
	if (argc != 2)
	{
		pipe_start(&pipe);
		pipe_file_get(&pipe, argc, argv);
		pipe_command_get(&pipe, argc, argv);
		show(&pipe);
	}
	pipe_pop(&pipe);
	//execve("/bin/ls", argv, "");
	return (0);
}

void show(t_pipe *pipe)
{
	t_chained	*update = pipe->cmd;
	t_chained	*flag;

	if (!pipe)
		return ;
	while (update)
	{
		t_command *command = update->data;
		printf("Name: %s Flag: ", command->name);
		flag = command->flag;
		while (flag)
		{
			printf("%s", (char *)flag->data);
			flag = flag->next;
		}
		update = update->next;
		printf("\n");
	}
}