/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:29 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>

void show(t_pipe *pipe);
void name_get(void *data, char **);

int	main(void)
{
	char buffer[] = "I am alive";
	char	*envp[] = {"-l"};

	pipe_process(buffer, name_get, envp);
	printf("keep going\n");
	printf("I am done\n");
	return (0);
}

void name_get(void *data, char **envp)
{
	if (!data)
		return ;
	char *parameter[] = {"executer_name", "main.c", "remover2.txt", NULL};
	pipe_process_execute("/bin", "cat", parameter, envp);
	//execve("/bin/cat", argv, envp);
}

void execute(int argc, char **argv)
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