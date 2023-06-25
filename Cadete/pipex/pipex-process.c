/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:45:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/25 16:26:59 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#define READ 0
#define WRITE 1

int pipe_process(void *data, void (*child_get)(void *data,char **envp), char **envp)
{
    int     fd[2];
    pid_t   pid;

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return (-1);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid > 0) // father process
    {
        close(fd[READ]);
        write(fd[WRITE], data, sizeof(data));
    }
    else // child process
    {
        close(fd[WRITE]);
        read(fd[READ], data, sizeof(data));
        if (child_get)
            child_get(data, envp);
        exit(0);
    }
    return (0);
}

void    pipe_process_execute(const char *path, char *app, char **parameter, char **unknown)
{
    char executor[64];
    sprintf(executor, "%s/%s",path, app);
    execve(executor, parameter, unknown);
}