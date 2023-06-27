/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:45:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/26 22:49:40 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#define READ 0
#define WRITE 1

//int pipe_process(void *data, void *command, 
//void (*child_get)(void *file, void *command))
//{
//    int     fd[2];
//    pid_t   pid;

//    if (pipe(fd) == -1)
//    {
//        perror("pipe");
//        return (-1);
//    }
//    pid = fork();
//    if (pid < 0)
//    {
//        perror("fork");
//        exit(1);
//    }
//    if (pid > 0) // father process
//    {
//        close(fd[READ]);
//        write(fd[WRITE], data, sizeof(data));
//    }
//    else // child process
//    {
//        close(fd[WRITE]);
//        read(fd[READ], data, sizeof(data));
//        if (child_get)
//            child_get(data, command);
//        exit(0);
//    }
//    return (0);
//}

void	pipe_process_execute(t_process *process)
{
	char	executor[1024];

	sprintf(executor, "%s/%s", process->path, process->app);
	/**
	if (descriptor->current == 0)
	{
		dup2(0, 0);
		dup2(command->fd[1], 1);
	}        
	if (command->current_command != 0
		&& command->current_command < command->max_command)
	{
		dup2(command->fd[0], 0);
		dup2(command->fd[1], 1);   
	}
	if (command->current_command == command_max)
	{
		//dup2(command->fd[0], 0);
		//dup2(1,)
	}
	*/
	execve(executor, process->parameter, process->flag);
}
